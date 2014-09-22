# `Source/core/layout`

This directory contains implementation of layout objects. It covers the
following document lifecycle states:

* LayoutSubtreeChange (`InLayoutSubtreeChange` and `LayoutSubtreeChangeClean`)
* PreLayout (`InPreLayout`)
* PerformLayout (`InPerformLayout`)
* AfterPerformLayout (`AfterPerformLayout` and `LayoutClean`)

Note that a new Blink layout system is under development. See the
[LayoutNG design document](https://docs.google.com/document/d/1uxbDh4uONFQOiGuiumlJBLGgO4KDWB8ZEkp7Rd47fw4/preview).

## Overflow rects and scroll offsets

PaintLayerScrollableArea uses a "scroll origin" to conceptually represent the distance between
the top-left corner of the box'es content rect and the top-left corner of its overflow rect
when the box is scrolled to the logical beginning of its content (e.g. all the way to the left for
LTR, all the way to the right for RTL).  For left-to-right and top-to-bottom flows, the scroll
origin is zero, i.e., the top/left of the overflow rect is at the same position as the top/left of
the box'es content rect when scrolled to the beginning of flow.  For right-to-left and bottom-to-top
flows, the overflow rect extends to the top/left of the client rect.

The default calculation for scroll origin is the distance between the top-left corner of the content
rect and the top-left corner of the overflow rect.  To illustrate, here is a box with left overflow and
no vertical scrollbar:

                                 content
                                   rect
                               |<-------->|
                        scroll
                        origin
                    |<-------->|
                     _____________________
                    |          |          |
                    |          |          |
                    |          |          |
    direction:rtl   |          |   box    |
                    |          |          |
                    |          |          |
                    |__________|__________|

                          overflow rect
                    |<--------------------->|


However, if the box has a scrollbar for the orthogonal direction (e.g., a vertical scrollbar
in a direction:rtl block), the size of the scrollbar must be added to the scroll origin calculation.
Here are two examples -- note that it doesn't matter whether the vertical scrollbar is placed on
the right or left of the box (the vertical scrollbar is the `|/|` part):

                                   content
                                     rect
                                 |<-------->|
                        scroll
                        origin
                    |<---------->|
                     _______________________
                    |          |/|          |
                    |          |/|          |
                    |          |/|          |
    direction:rtl   |          |/|   box    |
                    |          |/|          |
                    |          |/|          |
                    |__________|/|__________|

                          overflow rect
                    |<--------------------->|

                                     content
                                       rect
                                   |<-------->|
                          scroll
                          origin
                      |<---------->|
                         _______________________
                        |          |          |/|
                        |          |          |/|
                        |          |          |/|
    writing-mode:       |          |          |/|
      vertical-rl       |          |          |/|
                        |          |          |/|
                        |          |          |/|
                        |          |          |/|
                        |__________|__________|/|

                              overflow rect
                        |<--------------------->|

## Coordinate Spaces

Layout and Paint work with and frequently refer to three main coordinate spaces
(really two, with one variant):

* Physical coordinates: Corresponds to physical direction of the output per the
  physical display (screen, printed page). Generally used for painting, thus
  layout logic that feeds into paint may produce values in this space. CSS
  properties such as `top`, `right`, `bottom`, and `left` are in this space. See
  also the 'flipped block-flow direction' variant space below.

* Logical coordinates: Used in layout to allow for generalized positioning that
  fits with whatever the `writing-mode` and `direction` CSS property values may
  be. Properties named with `before`, `after`, `start` or `end` are in this
  space. These are also known respectively as 'logical top', 'logical bottom',
  'logical left', and 'logical right'.

* Physical coordinates with flipped block-flow direction: The same as 'physical
  coordinates', but for `writing-mode: vertical-rl` where blocks are laid out
  right-to-left, block position is "flipped" from the left to the right side of
  their containing block. This is essentially a mirror reflection horizontally
  across the center of a block's containing block.

  For `writing-mode` values other than `vertical-rl` there is no change from
  physical coordinates.

  Layout and paint logic reference this space to connote whether "flipping" has
  been applied to the values. Final painted output for "flipped block-flow"
  writing mode must, by definition, incorporate flipping. It can be expensive to
  look up the writing mode of an object.  Performing computation on values known
  to be in this space can save on the overhead required to unflip/reflip.

Example with `writing-mode: vertical-rl; direction: ltr`:

                       'top' / 'start' side

                        block-flow direction
              <------------------------------------ |
              ------------------------------------- |
              |        c   |          s           | |
    'left'    |        o   |          o           | |   inline     'right'
       /      |        n   |          m           | |  direction      /
    'after'   |        t   |          e           | |              'before'
     side     |        e   |                      | |                side
              |        n   |                      | |
              |        t   |                      | |
              ------------------------------------- v

                    'bottom' / 'end' side

Another example -- consider a relative-positioned element:

    <style>
    html {
        writing-mode: vertical-rl;
    }
    </style>
    <div id="container" style="background-color: lightBlue; width: 300px; height: 200px;">
      <div id="relpos" style="position: relative; top: 50px; left: -60px; width: 70px; height: 80px; background-color: red;"></div>
    </div>

The final location of these within an 800x600 frame is as:

    container: (492, 8  300x200)
    relpos:    (662, 58 70x80)

See the [diagram](resources/flipped-blocks-relpos.svg) for full detail on
dimensions of the involved elements.

Determining the paint invalidation rect for `relpos` via
`mapToVisualRectInAncestorSpace()` involves walking up the layout tree from
`relpos` flipping the rect within its container at each box. Below we sketch
each step as we recurse toward the top of the document, with 'this' on the left,
the current rect being mapped on the right, and explanation beneath each:

    LayoutBlockFlow (relative positioned) DIV id='relpos'   0,0    70x80

        Apply the relative position of 'relpos' while flipping within
        'container' to respect writing mode.

        170 = 300 (container width) - 70 (relpos width) - 60 (relpos left)
        50 = relpos top

    LayoutBlockFlow DIV id='container'                      170,50 70x80

        Since body has the same width as container, flipping has
        no effect on the rect in this step.

    LayoutBlockFlow BODY                                    170,50 70x80

        Flip within the html block, which is symmetrically 8px larger than body
        due to default margin.

    LayoutBlockFlow HTML                                    178,58 70x80

        Flip the rectangle within the view.

        662 = 800 (view width) - 316 (html width) + 178 (current rect left)

    LayoutView #document                                    662,58 70x80

Since relative-positioned elements are positioned via physical coordinates, and
flipping at each step mirrors the position based on the width of the containing
box at that step, we can only compute the final physical pixels in screen space
for a relative-positioned element if we walk up the full layout tree from the
starting object to the topmost view as described above.

For more examples of writing mode and direction combinations, see this
[demo page](http://pauljadam.com/demos/csstext.html) though note `horizontal-bt`
is obsolete.

### Flipped Block-Flow Coordinates

The nature of "flipping" a value as a mirror reflection within its containing
block is such that flipping twice with the same container will produce the
original result. Thus when working on involved logic it can be easy to
accidentally flip unnecessarily, since flipping (say) one too many times can be
"corrected" by flipping again. This can obviously lead to confusing and less
performant code, so care should be taken to understand and document any changes
to flipping logic.

Blink test coverage for features used in vertical writing modes, and
`vertical-rl` in particular, may not be as comprehensive as for horizontal
writing mode. Keep this in mind when writing new functionality or tests by
making sure to incorporate coverage for all writing modes when appropriate.

Values are generally transformed into flipped block-flow coordinates via a set
of methods on the involved layout objects. See in particular
`flipForWritingMode()`, `flipForWritingModeForChild()`, and `topLeftLocation()`.

`InlineBox::flipForWritingMode()` variants flip the input value within the
inline box's containing block.

`LayoutBox::flipForWritingMode()` variants flip the input value within the
referenced box.

`LayoutBox::flipForWritingModeForChild()` variants flip the input value within
the referenced box, offsetting for the specified child box's current x-position
and width. This is useful for a common pattern wherein we build up a point
location starting with the current location of the (child) box.

`LayoutBox::topLeftLocation()` performs flipping as needed. If the containing
block is not passed to the method, looking it up requires walking up the layout
tree, which can be expensive.

Note there are two primary similar, but slightly different, methods regarding
finding the containing block for an element:

* `LayoutObject::container()` returns the containing block for an element as
defined by CSS.
* `LayoutObject::containingBlock()` which returns the enclosing non-anonymous
block for an element. If the containing block is a relatively positioned inline,
it returns that inline's enclosing non-anonymous block. This is the one used by
`topLeftLocation()`.

There are other containing block methods in `LayoutObject` for special purposes
such as fixed position, absolute position, and paint invalidation.  Code will
sometimes just refer to the 'containing' element, which is an unfortunately
ambiguous term.  Paying close attention to which method was used to obtain the
containing element is important.

More complex web platform features such as tables, flexbox, and multicol are
typically implemented atop these primitives, along with checks such as
`isFlippedBlocksWritingMode()`, `isLeftToRightDirection()`, and
`isHorizontalWritingMode()`. See for example
`LayoutTableSection::logicalRectForWritingModeAndDirection()`,
`LayoutFlexibleBox::updateAutoMarginsInCrossAxis()` or
`LayoutMultiColumnFlowThread::flowThreadTranslationAtPoint()`.

## Geometry mapping

TODO(wkorman): Elaborate on:
* `mapToVisualRectInAncestorSpace()`
* `mapAncestorToLocal()`
* `Widget` and `FrameView` trees. Note the former will be done away with at some
  point per http://crbug.com/637460.
* `GeometryMapper` (or just point to its section in paint README). For now, see
  the
  [Web page geometries](https://docs.google.com/document/d/1WZKlOSUK4XI0Le0fgCsyUTVw0dTwutZXGWwzlHXewiU/preview)
  design document.

## Scrolling

TODO(wkorman): Provide an overview of scrolling. For now, the BlinkOn talk
on
[Scrolling in Blink](https://docs.google.com/presentation/d/1pwx0qBW4wSmYAOJxq2gb3SMvSTCHz2L2TFx_bjsvm8E/preview)
is a good overview.

## Glossaries

Here we provide a brief overview of key terms relevant to box flow, inline flow,
and text orientation.  For more detail see
[CSS Writing Modes Level 3](https://www.w3.org/TR/css-writing-modes-3/).

The
[CSS Logical Properties Level 1](https://drafts.csswg.org/css-logical-props/)
specification represents the latest CSSWG thinking on logical coordinate space
naming.  CSSWG has standardized on `block-start`, `block-end`, `inline-start`,
and `inline-end`, or just `start` and `end` when the axis is either implied or
irrelevant.

Note that much of the Blink code base predates the logical properties
specification and so does not yet reference logical direction consistently in
the stated manner, though we would like to head in that direction over time.
See also the *physical*, *flow-relative*, and *line-relative*
[abstract box terminology](https://www.w3.org/TR/css-writing-modes-3/#abstract-box)
specification.

* `writing-mode`: either horizontal or vertical, with vertical having either
  left-to-right or right-to-left block flow. Geometry is transposed for vertical
  writing mode. See calls to `transposed{Rect,Point,Size}()`.
* `direction`/`dir`: "inline base direction" of a box. One of `ltr` or
  `rtl`. See calls to `isLeftToRightDirection()`.
* `text-orientation`: orientation of text in a line. Only relevant for vertical
  modes.
* orthogonal flow: when a box has a writing mode perpendicular to its containing
  block. This can lead to complex cases. See
  [specification](https://www.w3.org/TR/css-writing-modes-3/#orthogonal-flows)
  for more.