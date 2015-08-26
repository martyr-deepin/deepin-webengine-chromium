// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/filters/audio_clock.h"

#include <algorithm>

#include "base/logging.h"
#include "media/base/buffers.h"

namespace media {

AudioClock::AudioClock(base::TimeDelta start_timestamp, int sample_rate)
    : start_timestamp_(start_timestamp),
      microseconds_per_frame_(
          static_cast<double>(base::Time::kMicrosecondsPerSecond) /
          sample_rate),
      total_buffered_frames_(0),
      front_timestamp_(start_timestamp),
      back_timestamp_(start_timestamp) {
}

AudioClock::~AudioClock() {
}

void AudioClock::WroteAudio(int frames_written,
                            int frames_requested,
                            int delay_frames,
                            double playback_rate) {
  DCHECK_GE(frames_written, 0);
  DCHECK_LE(frames_written, frames_requested);
  DCHECK_GE(delay_frames, 0);
  DCHECK_GE(playback_rate, 0);

  // First write: initialize buffer with silence.
  if (start_timestamp_ == front_timestamp_ && buffered_.empty())
    PushBufferedAudioData(delay_frames, 0.0);

  // Move frames from |buffered_| into the computed timestamp based on
  // |delay_frames|.
  //
  // The ordering of compute -> push -> pop eliminates unnecessary memory
  // reallocations in cases where |buffered_| gets emptied.
  const int64_t original_buffered_frames = total_buffered_frames_;
  int64_t frames_played =
      std::max(INT64_C(0), total_buffered_frames_ - delay_frames);
  front_timestamp_ += ComputeBufferedMediaTime(frames_played);
  PushBufferedAudioData(frames_written, playback_rate);
  PushBufferedAudioData(frames_requested - frames_written, 0.0);
  PopBufferedAudioData(frames_played);

  back_timestamp_ += base::TimeDelta::FromMicroseconds(
      frames_written * playback_rate * microseconds_per_frame_);

  // Ensure something crazy hasn't happened to desync the front and back values.
  DCHECK_LE(front_timestamp_.InMicroseconds(), back_timestamp_.InMicroseconds())
      << "frames_written=" << frames_written
      << ", frames_requested=" << frames_requested
      << ", delay_frames=" << delay_frames
      << ", playback_rate=" << playback_rate
      << ", frames_played=" << frames_played
      << ", original_buffered_frames=" << original_buffered_frames
      << ", total_buffered_frames_=" << total_buffered_frames_;

  // Update cached values.
  double scaled_frames = 0;
  double scaled_frames_at_same_rate = 0;
  bool found_silence = false;
  for (size_t i = 0; i < buffered_.size(); ++i) {
    if (buffered_[i].playback_rate == 0) {
      found_silence = true;
      continue;
    }

    // Any buffered silence breaks our contiguous stretch of audio data.
    if (found_silence)
      break;

    scaled_frames += (buffered_[i].frames * buffered_[i].playback_rate);

    if (i == 0)
      scaled_frames_at_same_rate = scaled_frames;
  }

  contiguous_audio_data_buffered_ = base::TimeDelta::FromMicroseconds(
      scaled_frames * microseconds_per_frame_);
  contiguous_audio_data_buffered_at_same_rate_ =
      base::TimeDelta::FromMicroseconds(scaled_frames_at_same_rate *
                                        microseconds_per_frame_);
}

void AudioClock::CompensateForSuspendedWrites(base::TimeDelta elapsed,
                                              int delay_frames) {
  const int64_t frames_elapsed =
      elapsed.InMicroseconds() / microseconds_per_frame_ + 0.5;

  // No need to do anything if we're within the limits of our played out audio
  // or there are no delay frames, the next WroteAudio() call will expire
  // everything correctly.
  if (frames_elapsed < total_buffered_frames_ || !delay_frames)
    return;

  // Otherwise, flush everything and prime with the delay frames.
  WroteAudio(0, 0, 0, 0);
  DCHECK(buffered_.empty());
  PushBufferedAudioData(delay_frames, 0.0);
}

base::TimeDelta AudioClock::TimeUntilPlayback(base::TimeDelta timestamp) const {
  DCHECK_GE(timestamp, front_timestamp_);
  DCHECK_LE(timestamp, back_timestamp_);

  int64_t frames_until_timestamp = 0;
  double timestamp_us = timestamp.InMicroseconds();
  double media_time_us = front_timestamp_.InMicroseconds();

  for (size_t i = 0; i < buffered_.size(); ++i) {
    // Leading silence is always accounted prior to anything else.
    if (buffered_[i].playback_rate == 0) {
      frames_until_timestamp += buffered_[i].frames;
      continue;
    }

    // Calculate upper bound on media time for current block of buffered frames.
    double delta_us = buffered_[i].frames * buffered_[i].playback_rate *
                      microseconds_per_frame_;
    double max_media_time_us = media_time_us + delta_us;

    // Determine amount of media time to convert to frames for current block. If
    // target timestamp falls within current block, scale the amount of frames
    // based on remaining amount of media time.
    if (timestamp_us <= max_media_time_us) {
      frames_until_timestamp +=
          buffered_[i].frames * (timestamp_us - media_time_us) / delta_us;
      break;
    }

    media_time_us = max_media_time_us;
    frames_until_timestamp += buffered_[i].frames;
  }

  return base::TimeDelta::FromMicroseconds(frames_until_timestamp *
                                           microseconds_per_frame_);
}

AudioClock::AudioData::AudioData(int64_t frames, double playback_rate)
    : frames(frames), playback_rate(playback_rate) {
}

void AudioClock::PushBufferedAudioData(int64_t frames, double playback_rate) {
  if (frames == 0)
    return;

  total_buffered_frames_ += frames;

  // Avoid creating extra elements where possible.
  if (!buffered_.empty() && buffered_.back().playback_rate == playback_rate) {
    buffered_.back().frames += frames;
    return;
  }

  buffered_.push_back(AudioData(frames, playback_rate));
}

void AudioClock::PopBufferedAudioData(int64_t frames) {
  DCHECK_LE(frames, total_buffered_frames_);

  total_buffered_frames_ -= frames;

  while (frames > 0) {
    int64_t frames_to_pop = std::min(buffered_.front().frames, frames);
    buffered_.front().frames -= frames_to_pop;
    if (buffered_.front().frames == 0)
      buffered_.pop_front();

    frames -= frames_to_pop;
  }
}

base::TimeDelta AudioClock::ComputeBufferedMediaTime(int64_t frames) const {
  DCHECK_LE(frames, total_buffered_frames_);

  double scaled_frames = 0;
  for (size_t i = 0; i < buffered_.size() && frames > 0; ++i) {
    int64_t min_frames = std::min(buffered_[i].frames, frames);
    scaled_frames += min_frames * buffered_[i].playback_rate;
    frames -= min_frames;
  }

  return base::TimeDelta::FromMicroseconds(scaled_frames *
                                           microseconds_per_frame_);
}

}  // namespace media