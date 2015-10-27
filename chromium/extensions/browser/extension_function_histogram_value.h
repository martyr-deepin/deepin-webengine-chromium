// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef EXTENSIONS_BROWSER_EXTENSION_FUNCTION_HISTOGRAM_VALUE_H_
#define EXTENSIONS_BROWSER_EXTENSION_FUNCTION_HISTOGRAM_VALUE_H_

namespace extensions {
namespace functions {

// Short version:
//  *Never* reorder or delete entries in the |HistogramValue| enumeration.
//  When creating a new extension function, add a new entry at the end of the
//  enum, just prior to ENUM_BOUNDARY.
//
// Long version:
//  This enumeration is used to associate a unique integer value to each
//  extension function so that their usage can be recorded in histogram charts.
//  Given we want the values recorded in the these charts to remain stable over
//  time for comparison purposes, once an entry has been added to the
//  enumeration, it should never be removed or moved to another spot in the
//  enum.
//
//  Here are instructions how to manage entries depending on what you are trying
//  to achieve.
//
//  1) Creating a new extension function:
//
//      Add a new entry at the end of the |HistogramValue| enum. The name of the
//      entry should follow this algorithm:
//      a) Take the string value passed as first argument to
//         DECLARE_EXTENSION_FUNCTION.
//      b) Replace '.' with '_'.
//      c) Make all letters uppercase.
//
//      Example: "tabs.create" -> TABS_CREATE
//
//  2) Deleting an existing function:
//
//      Given an existing entry should *never* be removed from this enumeration,
//      it is recommended to add a "DELETED_" prefix to the existing entry.
//
//  3) Renaming an existing function:
//
//      There are 2 options, depending if you want to keep accruing data in the
//      *existing* histogram stream or in a *new* one.
//
//      a) If you want keep recording usages of the extension function in the
//         *existing* histogram stream, simply rename the enum entry to match
//         the new extension function name, following the same naming rule as
//         mentioned in 1). The enum entry will keep the same underlying integer
//         value, so the same histogram stream will be used for recording
//         usages.
//
//      b) If you want start recording usages of the extension function to in a
//         *new* histogram stream, follow the instructions in step 1) and 2)
//         above. This will effectively deprecate the old histogram stream and
//         creates a new one for the new function name.
//
enum HistogramValue {
  UNKNOWN = 0,
  WEBNAVIGATION_GETALLFRAMES,
  BROWSINGDATA_REMOVEWEBSQL,
  ALARMS_CREATE,
  FILEMANAGERPRIVATEINTERNAL_REMOVEFILEWATCH,
  COOKIES_GET,
  FONTSETTINGS_GETMINIMUMFONTSIZE,
  CHROMEOSINFOPRIVATE_GET,
  BOOKMARKMANAGERPRIVATE_CUT,
  TABS_CAPTUREVISIBLETAB,
  MANAGEMENT_SETENABLED,
  HISTORY_DELETEALL,
  STORAGE_GET,
  SOCKET_SETKEEPALIVE,
  DOWNLOADS_CANCEL,
  BOOKMARKS_CREATE,
  BOOKMARKS_UPDATE,
  FILEMANAGERPRIVATE_GETDRIVEFILES,
  TERMINALPRIVATE_ONTERMINALRESIZE,
  DELETED_FILEMANAGERPRIVATE_REQUESTDIRECTORYREFRESH,
  BLUETOOTH_GETADAPTERSTATE,
  FILEMANAGERPRIVATEINTERNAL_CANCELFILETRANSFERS,
  FILEMANAGERPRIVATEINTERNAL_PINDRIVEFILE,
  SOCKET_WRITE,
  OMNIBOX_SETDEFAULTSUGGESTION,
  TTS_SPEAK,
  WALLPAPERPRIVATE_RESTOREMINIMIZEDWINDOWS,
  BROWSINGDATA_REMOVEHISTORY,
  DELETED_FILEMANAGERPRIVATE_ISFULLSCREEN,
  AUTOTESTPRIVATE_LOGOUT,
  EXPERIMENTAL_HISTORY_GETMOSTVISITED,
  DELETED_BLUETOOTH_DISCONNECT,
  DELETED_BLUETOOTH_SETOUTOFBANDPAIRINGDATA,
  BOOKMARKMANAGERPRIVATE_CANPASTE,
  AUTOTESTPRIVATE_RESTART,
  USB_CLAIMINTERFACE,
  MEDIAPLAYERPRIVATE_SETWINDOWHEIGHT,
  DELETED_EXPERIMENTAL_PROCESSES_GETPROCESSINFO,
  HISTORY_GETVISITS,
  SOCKET_BIND,
  TABS_MOVE,
  SOCKET_DISCONNECT,
  FILESYSTEM_GETWRITABLEENTRY,
  SYNCFILESYSTEM_REQUESTFILESYSTEM,
  COMMANDS_GETALL,
  EXPERIMENTAL_DISCOVERY_REMOVESUGGESTION,
  VIRTUALKEYBOARDPRIVATE_SENDKEYEVENT,
  BOOKMARKMANAGERPRIVATE_GETSUBTREE,
  DELETED_EXPERIMENTAL_RLZ_RECORDPRODUCTEVENT,
  BOOKMARKS_GETRECENT,
  APP_CURRENTWINDOWINTERNAL_SETBOUNDS,
  CLOUDPRINTPRIVATE_SETUPCONNECTOR,
  SERIAL_SETCONTROLSIGNALS,
  DELETED_FILEMANAGERPRIVATE_SETLASTMODIFIED,
  IDLE_SETDETECTIONINTERVAL,
  FILEMANAGERPRIVATEINTERNAL_GETFILETASKS,
  WEBSTOREPRIVATE_GETSTORELOGIN,
  SYSTEMPRIVATE_GETINCOGNITOMODEAVAILABILITY,
  IDLTEST_SENDARRAYBUFFERVIEW,
  SOCKET_SETNODELAY,
  APP_CURRENTWINDOWINTERNAL_SHOW,
  WEBSTOREPRIVATE_GETBROWSERLOGIN,
  EXPERIMENTAL_IDENTITY_GETAUTHTOKEN,
  DELETED_SYSTEMINFO_DISPLAY_GETDISPLAYINFO,
  BROWSINGDATA_REMOVEPLUGINDATA,
  SOCKET_LISTEN,
  MEDIAGALLERIES_GETMEDIAFILESYSTEMS,
  DOWNLOADS_OPEN,
  TABS_EXECUTESCRIPT,
  SYNCFILESYSTEM_GETUSAGEANDQUOTA,
  INPUTMETHODPRIVATE_GET,
  USB_CLOSEDEVICE,
  TTS_STOP,
  DELETED_SERIAL_GETPORTS,
  DELETED_FILEMANAGERPRIVATE_CLEARDRIVECACHE,
  SERIAL_GETCONTROLSIGNALS,
  DELETED_DEVELOPERPRIVATE_ENABLE,
  FILEMANAGERPRIVATEINTERNAL_GETENTRYPROPERTIES,
  USB_FINDDEVICES,
  BOOKMARKMANAGERPRIVATE_DROP,
  DELETED_FILEMANAGERPRIVATE_GETFILETRANSFERS,
  INPUT_IME_SETMENUITEMS,
  BOOKMARKS_EXPORT,
  HISTORY_SEARCH,
  TTSENGINE_SENDTTSEVENT,
  ACCESSIBILITY_PRIVATE_GETALERTSFORTAB,
  BOOKMARKS_IMPORT,
  SYNCFILESYSTEM_DELETEFILESYSTEM,
  DEBUGGER_SENDCOMMAND,
  DEBUGGER_DETACH,
  METRICSPRIVATE_RECORDSMALLCOUNT,
  APP_CURRENTWINDOWINTERNAL_MINIMIZE,
  DEVELOPERPRIVATE_AUTOUPDATE,
  DNS_RESOLVE,
  DELETED_EXPERIMENTAL_SYSTEMINFO_MEMORY_GET,
  HISTORY_ADDURL,
  TABS_GET,
  BROWSERACTION_SETBADGETEXT,
  TABS_RELOAD,
  WINDOWS_CREATE,
  DEVELOPERPRIVATE_LOADUNPACKED,
  DELETED_DOWNLOADS_SETDESTINATION,
  DELETED_EXPERIMENTAL_PROCESSES_GETPROCESSIDFORTAB,
  BOOKMARKS_GETCHILDREN,
  BROWSERACTION_GETTITLE,
  TERMINALPRIVATE_OPENTERMINALPROCESS,
  DELETED_SERIAL_CLOSE,
  CONTEXTMENUS_REMOVE,
  FILESYSTEM_REQUESTFILESYSTEM,
  ECHOPRIVATE_GETREGISTRATIONCODE,
  TABS_GETCURRENT,
  FONTSETTINGS_CLEARDEFAULTFIXEDFONTSIZE,
  MEDIAPLAYERPRIVATE_CLOSEWINDOW,
  WEBREQUESTINTERNAL_ADDEVENTLISTENER,
  CLOUDPRINTPRIVATE_GETPRINTERS,
  STORAGE_SET,
  FONTSETTINGS_GETDEFAULTFONTSIZE,
  EXTENSION_SETUPDATEURLDATA,
  DELETED_SERIAL_WRITE,
  IDLE_QUERYSTATE,
  DELETED_EXPERIMENTAL_RLZ_GETACCESSPOINTRLZ,
  WEBSTOREPRIVATE_SETSTORELOGIN,
  DELETED_PAGEACTIONS_ENABLEFORTAB,
  COOKIES_SET,
  CONTENTSETTINGS_SET,
  CONTEXTMENUS_REMOVEALL,
  TABS_INSERTCSS,
  WEBREQUEST_HANDLERBEHAVIORCHANGED,
  INPUT_IME_SETCURSORPOSITION,
  OMNIBOX_SENDSUGGESTIONS,
  SYSTEMINDICATOR_ENABLE,
  EVENTS_GETRULES,
  BOOKMARKMANAGERPRIVATE_COPY,
  SOCKET_RECVFROM,
  TABS_GETALLINWINDOW,
  CONTEXTMENUS_UPDATE,
  BOOKMARKS_SEARCH,
  EXPERIMENTAL_APP_CLEARALLNOTIFICATIONS,
  DELETED_BLUETOOTH_GETLOCALOUTOFBANDPAIRINGDATA,
  SYSTEMPRIVATE_GETUPDATESTATUS,
  FONTSETTINGS_CLEARMINIMUMFONTSIZE,
  DELETED_FILEMANAGERPRIVATE_GETFILELOCATIONS,
  EXPERIMENTAL_DISCOVERY_SUGGEST,
  FILEMANAGERPRIVATEINTERNAL_SETDEFAULTTASK,
  BROWSERACTION_GETBADGETEXT,
  APP_CURRENTWINDOWINTERNAL_HIDE,
  SOCKET_CONNECT,
  BOOKMARKS_GETSUBTREE,
  HISTORY_DELETEURL,
  DELETED_EXPERIMENTAL_MEDIAGALLERIES_ASSEMBLEMEDIAFILE,
  BOOKMARKMANAGERPRIVATE_STARTDRAG,
  BROWSINGDATA_REMOVEPASSWORDS,
  DOWNLOADS_DRAG,
  INPUT_IME_SETCOMPOSITION,
  METRICSPRIVATE_RECORDUSERACTION,
  USB_RELEASEINTERFACE,
  PAGEACTION_GETPOPUP,
  DELETED_SCRIPTBADGE_GETATTENTION,
  FONTSETTINGS_GETFONTLIST,
  PERMISSIONS_CONTAINS,
  DELETED_SCRIPTBADGE_GETPOPUP,
  ACCESSIBILITY_PRIVATE_GETFOCUSEDCONTROL,
  DEVELOPERPRIVATE_GETSTRINGS,
  METRICSPRIVATE_RECORDMEDIUMCOUNT,
  MANAGEMENT_GET,
  PERMISSIONS_GETALL,
  DOWNLOADS_SHOW,
  DELETED_EXPERIMENTAL_RLZ_CLEARPRODUCTSTATE,
  TABS_REMOVE,
  MANAGEMENT_GETPERMISSIONWARNINGSBYID,
  WINDOWS_GET,
  FILEMANAGERPRIVATEINTERNAL_EXECUTETASK,
  TTS_GETVOICES,
  MANAGEMENT_GETALL,
  MANAGEMENT_GETPERMISSIONWARNINGSBYMANIFEST,
  APP_CURRENTWINDOWINTERNAL_CLEARATTENTION,
  AUTOTESTPRIVATE_SHUTDOWN,
  FONTSETTINGS_CLEARDEFAULTFONTSIZE,
  BOOKMARKS_GETTREE,
  FILEMANAGERPRIVATE_SELECTFILES,
  RUNTIME_GETBACKGROUNDPAGE,
  DELETED_EXPERIMENTAL_RECORD_REPLAYURLS,
  WEBSTOREPRIVATE_COMPLETEINSTALL,
  DELETED_EXPERIMENTAL_SPEECHINPUT_START,
  COOKIES_GETALL,
  DOWNLOADS_GETFILEICON,
  PAGEACTION_GETTITLE,
  BROWSINGDATA_REMOVE,
  DELETED_SERIAL_OPEN,
  FILESYSTEM_GETDISPLAYPATH,
  FILEMANAGERPRIVATE_FORMATVOLUME,
  BOOKMARKS_GET,
  DELETED_MANAGEDMODEPRIVATE_GET,
  ALARMS_CLEAR,
  SYNCFILESYSTEM_GETFILESYNCSTATUS,
  SOCKET_GETINFO,
  WEBSTOREPRIVATE_INSTALLBUNDLE,
  BROWSERACTION_ENABLE,
  METRICSPRIVATE_RECORDMEDIUMTIME,
  PAGEACTION_SETTITLE,
  CLOUDPRINTPRIVATE_GETHOSTNAME,
  CONTENTSETTINGS_GETRESOURCEIDENTIFIERS,
  SOCKET_CREATE,
  DEVELOPERPRIVATE_RELOAD,
  FILEMANAGERPRIVATE_GETVOLUMEMETADATALIST,
  APP_RUNTIME_POSTINTENTRESPONSE,
  DELETED_MANAGEDMODEPRIVATE_SETPOLICY,
  WEBSTOREPRIVATE_BEGININSTALLWITHMANIFEST3,
  WALLPAPERPRIVATE_SETWALLPAPER,
  USB_CONTROLTRANSFER,
  DELETED_EXPERIMENTAL_SPEECHINPUT_STOP,
  USB_BULKTRANSFER,
  DELETED_FILEMANAGERPRIVATE_GETVOLUMEMETADATA,
  PAGECAPTURE_SAVEASMHTML,
  EXTENSION_ISALLOWEDINCOGNITOACCESS,
  BROWSINGDATA_REMOVEAPPCACHE,
  APP_CURRENTWINDOWINTERNAL_DRAWATTENTION,
  METRICSPRIVATE_RECORDCOUNT,
  USB_INTERRUPTTRANSFER,
  TYPES_CHROMESETTING_CLEAR,
  INPUT_IME_COMMITTEXT,
  IDLTEST_SENDARRAYBUFFER,
  WALLPAPERPRIVATE_SETWALLPAPERIFEXISTS,
  SOCKET_ACCEPT,
  WEBNAVIGATION_GETFRAME,
  EXPERIMENTAL_POWER_RELEASEKEEPAWAKE,
  APP_CURRENTWINDOWINTERNAL_SETICON,
  PUSHMESSAGING_GETCHANNELID,
  EXPERIMENTAL_INFOBARS_SHOW,
  INPUT_IME_SETCANDIDATEWINDOWPROPERTIES,
  METRICSPRIVATE_RECORDPERCENTAGE,
  TYPES_CHROMESETTING_GET,
  WINDOWS_GETLASTFOCUSED,
  DELETED_MANAGEDMODEPRIVATE_GETPOLICY,
  STORAGE_CLEAR,
  STORAGE_GETBYTESINUSE,
  TABS_QUERY,
  PAGEACTION_SETPOPUP,
  DEVELOPERPRIVATE_INSPECT,
  DOWNLOADS_SEARCH,
  FONTSETTINGS_CLEARFONT,
  WINDOWS_UPDATE,
  BOOKMARKMANAGERPRIVATE_CANOPENNEWWINDOWS,
  SERIAL_FLUSH,
  BROWSERACTION_SETTITLE,
  BOOKMARKMANAGERPRIVATE_CANEDIT,
  WALLPAPERPRIVATE_SETCUSTOMWALLPAPER,
  BOOKMARKS_REMOVE,
  INPUT_IME_SETCANDIDATES,
  TERMINALPRIVATE_CLOSETERMINALPROCESS,
  HISTORY_DELETERANGE,
  IDLTEST_GETARRAYBUFFER,
  TERMINALPRIVATE_SENDINPUT,
  TABS_HIGHLIGHT,
  BLUETOOTH_STARTDISCOVERY,
  FILEMANAGERPRIVATE_SELECTFILE,
  WINDOWS_GETCURRENT,
  DEBUGGER_ATTACH,
  WALLPAPERPRIVATE_SAVETHUMBNAIL,
  INPUT_IME_KEYEVENTHANDLED,
  FONTSETTINGS_SETDEFAULTFONTSIZE,
  RUNTIME_REQUESTUPDATECHECK,
  PAGEACTION_SETICON,
  BROWSERACTION_SETBADGEBACKGROUNDCOLOR,
  DEVELOPERPRIVATE_GETITEMSINFO,
  BLUETOOTH_STOPDISCOVERY,
  COOKIES_REMOVE,
  DELETED_EXPERIMENTAL_RLZ_SENDFINANCIALPING,
  TABCAPTURE_GETCAPTUREDTABS,
  WINDOWS_REMOVE,
  WALLPAPERPRIVATE_GETOFFLINEWALLPAPERLIST,
  BROWSERACTION_GETBADGEBACKGROUNDCOLOR,
  DELETED_PAGEACTIONS_DISABLEFORTAB,
  DELETED_DEVELOPERPRIVATE_ALLOWFILEACCESS,
  FILEMANAGERPRIVATE_REMOVEMOUNT,
  DELETED_BLUETOOTH_CONNECT,
  TABCAPTURE_CAPTURE,
  NOTIFICATIONS_CREATE,
  TABS_DUPLICATE,
  DELETED_BLUETOOTH_WRITE,
  PAGEACTION_SHOW,
  WALLPAPERPRIVATE_GETTHUMBNAIL,
  DOWNLOADS_PAUSE,
  PERMISSIONS_REQUEST,
  TOPSITES_GET,
  BROWSINGDATA_REMOVEDOWNLOADS,
  BROWSINGDATA_REMOVELOCALSTORAGE,
  FILEBROWSERHANDLERINTERNAL_SELECTFILE,
  INPUT_IME_UPDATEMENUITEMS,
  FILEMANAGERPRIVATE_GETSTRINGS,
  CONTENTSETTINGS_GET,
  FONTSETTINGS_SETDEFAULTFIXEDFONTSIZE,
  EXPERIMENTAL_APP_NOTIFY,
  METRICSPRIVATE_RECORDLONGTIME,
  SOCKET_READ,
  DELETED_EXPERIMENTAL_PROCESSES_TERMINATE,
  METRICSPRIVATE_RECORDTIME,
  BOOKMARKMANAGERPRIVATE_GETSTRINGS,
  USB_ISOCHRONOUSTRANSFER,
  PERMISSIONS_REMOVE,
  MANAGEMENT_UNINSTALL,
  I18N_GETACCEPTLANGUAGES,
  MANAGEMENT_LAUNCHAPP,
  INPUT_IME_CLEARCOMPOSITION,
  ALARMS_GETALL,
  DIAL_DISCOVERNOW,
  TYPES_CHROMESETTING_SET,
  BROWSERACTION_SETICON,
  ACCESSIBILITY_PRIVATE_SETACCESSIBILITYENABLED,
  DELETED_FILEMANAGERPRIVATE_VIEWFILES,
  DELETED_BLUETOOTH_GETSERVICES,
  TABS_UPDATE,
  BROWSINGDATA_REMOVEFORMDATA,
  DELETED_FILEMANAGERPRIVATE_RELOADDRIVE,
  ALARMS_GET,
  BROWSINGDATA_REMOVEINDEXEDDB,
  FILEMANAGERPRIVATEINTERNAL_ADDFILEWATCH,
  CONTENTSETTINGS_CLEAR,
  FILEMANAGERPRIVATE_GETPREFERENCES,
  BOOKMARKMANAGERPRIVATE_PASTE,
  FILESYSTEM_ISWRITABLEENTRY,
  USB_SETINTERFACEALTERNATESETTING,
  FONTSETTINGS_SETMINIMUMFONTSIZE,
  BROWSERACTION_GETPOPUP,
  SOCKET_DESTROY,
  BLUETOOTH_GETDEVICES,
  ALARMS_CLEARALL,
  FONTSETTINGS_GETDEFAULTFIXEDFONTSIZE,
  FILEMANAGERPRIVATEINTERNAL_ZIPSELECTION,
  SYSTEMINDICATOR_DISABLE,
  DELETED_SCRIPTBADGE_SETPOPUP,
  EXTENSION_ISALLOWEDFILESCHEMEACCESS,
  EXPERIMENTAL_IDENTITY_LAUNCHWEBAUTHFLOW,
  FILEMANAGERPRIVATE_GETDRIVECONNECTIONSTATE,
  TABS_DETECTLANGUAGE,
  METRICSPRIVATE_RECORDVALUE,
  BOOKMARKMANAGERPRIVATE_SORTCHILDREN,
  DELETED_SERIAL_READ,
  APP_CURRENTWINDOWINTERNAL_MAXIMIZE,
  EXPERIMENTAL_DISCOVERY_CLEARALLSUGGESTIONS,
  DELETED_MANAGEDMODEPRIVATE_ENTER,
  DELETED_FILEMANAGERPRIVATE_TRANSFERFILE,
  BROWSERACTION_SETPOPUP,
  TABS_GETSELECTED,
  FONTSETTINGS_GETFONT,
  DELETED_BLUETOOTH_READ,
  WEBREQUESTINTERNAL_EVENTHANDLED,
  EVENTS_ADDRULES,
  CONTEXTMENUS_CREATE,
  MEDIAPLAYERPRIVATE_GETPLAYLIST,
  DOWNLOADS_ERASE,
  DELETED_EXPERIMENTAL_RECORD_CAPTUREURLS,
  TTS_ISSPEAKING,
  BOOKMARKS_REMOVETREE,
  FILEMANAGERPRIVATE_SEARCHDRIVE,
  DELETED_EXPERIMENTAL_SYSTEMINFO_CPU_GET,
  FILEMANAGERPRIVATE_SETPREFERENCES,
  FONTSETTINGS_SETFONT,
  SOCKET_GETNETWORKLIST,
  BOOKMARKS_MOVE,
  WALLPAPERPRIVATE_MINIMIZEINACTIVEWINDOWS,
  STORAGE_REMOVE,
  AUTOTESTPRIVATE_LOGINSTATUS,
  TABS_CREATE,
  FILEMANAGERPRIVATE_CANCELDIALOG,
  BROWSINGDATA_REMOVECOOKIES,
  FILESYSTEM_CHOOSEENTRY,
  MEDIAPLAYERPRIVATE_PLAY,
  WEBSTOREPRIVATE_GETWEBGLSTATUS,
  SOCKET_SENDTO,
  BROWSINGDATA_REMOVEFILESYSTEMS,
  WALLPAPERPRIVATE_GETSTRINGS,
  BROWSINGDATA_REMOVECACHE,
  BOOKMARKMANAGERPRIVATE_RECORDLAUNCH,
  BROWSERACTION_DISABLE,
  DELETED_EXPERIMENTAL_SPEECHINPUT_ISRECORDING,
  APP_WINDOW_CREATE,
  RUNTIME_RELOAD,
  EXPERIMENTAL_POWER_REQUESTKEEPAWAKE,
  SYSTEMINDICATOR_SETICON,
  FILEMANAGERPRIVATE_ADDMOUNT,
  APP_CURRENTWINDOWINTERNAL_FOCUS,
  EVENTS_REMOVERULES,
  DOWNLOADS_DOWNLOAD,
  WINDOWS_GETALL,
  DELETED_FILEMANAGERPRIVATE_TOGGLEFULLSCREEN,
  APP_CURRENTWINDOWINTERNAL_RESTORE,
  DELETED_WEBSOCKETPROXYPRIVATE_GETPASSPORTFORTCP,
  PAGEACTION_HIDE,
  DELETED_EXPERIMENTAL_SYSTEMINFO_STORAGE_GET,
  DOWNLOADS_ACCEPTDANGER,
  DELETED_WEBSOCKETPROXYPRIVATE_GETURLFORTCP,
  FILEMANAGERPRIVATE_GETSIZESTATS,
  DOWNLOADS_RESUME,
  COOKIES_GETALLCOOKIESTORES,
  DELETED_MEDIAGALLERIESPRIVATE_ADDGALLERYWATCH,
  DELETED_MEDIAGALLERIESPRIVATE_REMOVEGALLERYWATCH,
  DELETED_WEBVIEW_EXECUTESCRIPT,
  NOTIFICATIONS_UPDATE,
  NOTIFICATIONS_CLEAR,
  DELETED_SESSIONRESTORE_GETRECENTLYCLOSED,
  DELETED_SESSIONRESTORE_RESTORE,
  MANAGEMENT_UNINSTALLSELF,
  ECHOPRIVATE_GETOOBETIMESTAMP,
  FILEMANAGERPRIVATEINTERNAL_VALIDATEPATHNAMELENGTH,
  BROWSINGDATA_SETTINGS,
  WEBSTOREPRIVATE_GETISLAUNCHERENABLED,
  NETWORKINGPRIVATE_GETPROPERTIES,
  NETWORKINGPRIVATE_GETVISIBLENETWORKS,
  NETWORKINGPRIVATE_STARTCONNECT,
  NETWORKINGPRIVATE_STARTDISCONNECT,
  DELETED_MEDIAGALLERIESPRIVATE_GETALLGALLERYWATCH,
  DELETED_MEDIAGALLERIESPRIVATE_REMOVEALLGALLERYWATCH,
  FILEMANAGERPRIVATE_SEARCHDRIVEMETADATA,
  DELETED_ECHOPRIVATE_CHECKALLOWREDEEMOFFERS,
  DELETED_MEDIAGALLERIESPRIVATE_EJECTDEVICE,
  FILEMANAGERPRIVATE_LOGOUTUSERFORREAUTHENTICATION,
  DEVELOPERPRIVATE_CHOOSEPATH,
  DEVELOPERPRIVATE_PACKDIRECTORY,
  NETWORKINGPRIVATE_VERIFYDESTINATION,
  NETWORKINGPRIVATE_VERIFYANDENCRYPTCREDENTIALS,
  NETWORKINGPRIVATE_VERIFYANDENCRYPTDATA,
  DEVELOPERPRIVATE_RESTART,
  DELETED_DEVELOPERPRIVATE_ALLOWINCOGNITO,
  INPUT_IME_DELETESURROUNDINGTEXT,
  DELETED_FILEMANAGERPRIVATE_OPENNEWWINDOW,
  CLOUDPRINTPRIVATE_GETCLIENTID,
  ECHOPRIVATE_GETUSERCONSENT,
  SYNCFILESYSTEM_SETCONFLICTRESOLUTIONPOLICY,
  SYNCFILESYSTEM_GETCONFLICTRESOLUTIONPOLICY,
  NETWORKINGPRIVATE_SETPROPERTIES,
  NETWORKINGPRIVATE_GETSTATE,
  POWER_REQUESTKEEPAWAKE,
  POWER_RELEASEKEEPAWAKE,
  WALLPAPERPRIVATE_SETCUSTOMWALLPAPERLAYOUT,
  DOWNLOADSINTERNAL_DETERMINEFILENAME,
  SYNCFILESYSTEM_GETFILESYNCSTATUSES,
  DELETED_MEDIAGALLERIESPRIVATE_GETHANDLERS,
  WALLPAPERPRIVATE_RESETWALLPAPER,
  DEVELOPERPRIVATE_PERMISSIONS,
  WEBSTOREPRIVATE_ENABLEAPPLAUNCHER,
  APP_CURRENTWINDOWINTERNAL_FULLSCREEN,
  DEVELOPERPRIVATE_LOADUNPACKEDCROS,
  NETWORKINGPRIVATE_REQUESTNETWORKSCAN,
  ENTERPRISE_PLATFORMKEYSPRIVATE_CHALLENGEMACHINEKEY,
  ENTERPRISE_PLATFORMKEYSPRIVATE_CHALLENGEUSERKEY,
  DEVELOPERPRIVATE_LOADPROJECTTOSYNCFS,
  DEVELOPERPRIVATE_GETPROJECTSINFO,
  DEVELOPERPRIVATE_LOADPROJECT,
  COMMANDLINEPRIVATE_HASSWITCH,
  NETWORKINGPRIVATE_GETMANAGEDPROPERTIES,
  LOCATION_WATCHLOCATION,
  LOCATION_CLEARWATCH,
  DELETED_BLUETOOTH_ADDPROFILE,
  DELETED_BLUETOOTH_REMOVEPROFILE,
  DELETED_BLUETOOTH_GETPROFILES,
  EXPERIMENTAL_IDENTITY_REMOVECACHEDAUTHTOKEN,
  AUDIO_GETINFO,
  AUDIO_SETACTIVEDEVICES,
  AUDIO_SETPROPERTIES,
  USB_RESETDEVICE,
  SOCKET_MULTICAST_JOIN_GROUP,
  SOCKET_MULTICAST_LEAVE_GROUP,
  SOCKET_MULTICAST_SET_TIME_TO_LIVE,
  SOCKET_MULTICAST_SET_LOOPBACK_MODE,
  SOCKET_MULTICAST_GET_JOINED_GROUPS,
  ACCESSIBILITY_PRIVATE_SETNATIVEACCESSIBILITYENABLED,
  RUNTIME_GETPLATFORMINFO,
  DELETED_WEBVIEW_INSERTCSS,
  METRICSPRIVATE_GETISCRASHRECORDINGENABLED,
  DELETED_IDENTITYPRIVATE_GETSTRINGS,
  NOTIFICATIONS_GET_ALL,
  USB_LISTINTERFACES,
  FILESYSTEM_RETAINENTRY,
  FILESYSTEM_ISRESTORABLE,
  FILESYSTEM_RESTOREENTRY,
  RUNTIME_SETUNINSTALLURL,
  INPUTMETHODPRIVATE_STARTIME,
  MUSICMANAGERPRIVATE_GETDEVICEID,
  TTS_PAUSE,
  TTS_RESUME,
  DELETED_SYSTEMINFO_CPU_GET,
  DELETED_EXPERIMENTAL_SYSTEMINFO_STORAGE_ADDWATCH,
  DELETED_EXPERIMENTAL_SYSTEMINFO_STORAGE_REMOVEWATCH,
  DELETED_EXPERIMENTAL_SYSTEMINFO_STORAGE_GETALLWATCH,
  DELETED_EXPERIMENTAL_SYSTEMINFO_STORAGE_REMOVEALLWATCH,
  DELETED_SYSTEMINFO_MEMORY_GET,
  ACTIVITYLOGPRIVATE_GETEXTENSIONACTIVITIES,
  RUNTIME_GETPACKAGEDIRECTORYENTRY,
  DELETED_SYSTEMINFO_DISPLAY_SETDISPLAYPROPERTIES,
  FEEDBACKPRIVATE_GETUSEREMAIL,
  FEEDBACKPRIVATE_GETSYSTEMINFORMATION,
  FEEDBACKPRIVATE_SENDFEEDBACK,
  VIRTUALKEYBOARDPRIVATE_INSERTTEXT,
  DIAGNOSTICS_SENDPACKET,
  METRICSPRIVATE_GETFIELDTRIAL,
  FILEMANAGERPRIVATE_ZOOM,
  DELETED_WEBVIEW_GO,
  WEBSTOREPRIVATE_ISININCOGNITOMODEFUNCTION,
  FILEMANAGERPRIVATE_REQUESTACCESSTOKEN,
  DELETED_WEBVIEW_STOP,
  DELETED_WEBVIEW_RELOAD,
  DELETED_WEBVIEW_TERMINATE,
  TYPES_PRIVATE_CHROMEDIRECTSETTING_GET,
  TYPES_PRIVATE_CHROMEDIRECTSETTING_SET,
  TYPES_PRIVATE_CHROMEDIRECTSETTING_CLEAR,
  DELETED_EXPERIMENTAL_SYSTEMINFO_STORAGE_EJECTDEVICE,
  SYSTEM_CPU_GETINFO,
  BOOKMARKMANAGERPRIVATE_REMOVETREES,
  SYSTEM_DISPLAY_GETINFO,
  SYSTEM_DISPLAY_SETDISPLAYPROPERTIES,
  SYSTEM_MEMORY_GETINFO,
  FILEMANAGERPRIVATEINTERNAL_GETSHAREURL,
  SYSTEM_STORAGE_GETINFO,
  SYSTEM_STORAGE_EJECTDEVICE,
  DELETED_SYSTEM_STORAGE_ADDAVAILABLECAPACITYWATCH,
  DELETED_SYSTEM_STORAGE_REMOVEAVAILABLECAPACITYWATCH,
  DELETED_SYSTEM_STORAGE_GETALLAVAILABLECAPACITYWATCHES,
  DELETED_SYSTEM_STORAGE_REMOVEALLAVAILABLECAPACITYWATCHES,
  DOWNLOADS_REMOVEFILE,
  DOWNLOADS_SHOWDEFAULTFOLDER,
  INFOBARS_SHOW,
  DOWNLOADS_SETSHELFENABLED,
  IMAGEWRITER_WRITEFROMURL,
  IMAGEWRITER_WRITEFROMFILE,
  IMAGEWRITER_CANCELWRITE,
  IMAGEWRITER_DESTROYPARTITIONS,
  FEEDBACKPRIVATE_GETSTRINGS,
  LOGPRIVATE_GETHISTORICAL,
  VIRTUALKEYBOARDPRIVATE_MOVECURSOR,
  METRICSPRIVATE_GETVARIATIONPARAMS,
  DELETED_WEBVIEW_SETPERMISSION,
  DESKTOPCAPTURE_CHOOSEDESKTOPMEDIA,
  APP_CURRENTWINDOWINTERNAL_SETSHAPE,
  PROCESSES_GETPROCESSINFO,
  PROCESSES_GETPROCESSIDFORTAB,
  PROCESSES_TERMINATE,
  SOCKETS_UDP_CREATE,
  SOCKETS_UDP_UPDATE,
  SOCKETS_UDP_BIND,
  SOCKETS_UDP_SEND,
  SOCKETS_UDP_CLOSE,
  SOCKETS_UDP_GETINFO,
  SOCKETS_UDP_GETSOCKETS,
  SOCKETS_UDP_JOINGROUP,
  SOCKETS_UDP_LEAVEGROUP,
  SOCKETS_UDP_SETMULTICASTTIMETOLIVE,
  SOCKETS_UDP_SETMULTICASTLOOPBACKMODE,
  SOCKETS_UDP_GETJOINEDGROUPS,
  SIGNED_IN_DEVICES_GET,
  AUTOTESTPRIVATE_SIMULATEASANMEMORYBUG,
  DELETED_WEBVIEW_CLEARDATA,
  SESSIONS_GETRECENTLYCLOSED,
  SESSIONS_GETDEVICES,
  SESSIONS_RESTORE,
  SYNCFILESYSTEM_GETSERVICESTATUS,
  ECHOPRIVATE_SETOFFERINFO,
  ECHOPRIVATE_GETOFFERINFO,
  DEVELOPERPRIVATE_ISPROFILEMANAGED,
  DELETED_FILEMANAGERPRIVATE_INSTALLWEBSTOREITEM,
  FILEMANAGERPRIVATEINTERNAL_STARTCOPY,
  FILEMANAGERPRIVATE_CANCELCOPY,
  NETWORKINGPRIVATE_CREATENETWORK,
  BRAILLEDISPLAYPRIVATE_GETDISPLAYSTATE,
  BRAILLEDISPLAYPRIVATE_WRITEDOTS,
  USB_GETDEVICES,
  USB_REQUESTACCESS,
  USB_OPENDEVICE,
  ACTIVITYLOGPRIVATE_DELETEDATABASE,
  ACTIVITYLOGPRIVATE_DELETEURLS,
  FILEMANAGERPRIVATE_REQUESTWEBSTOREACCESSTOKEN,
  IMAGEWRITER_LISTREMOVABLESTORAGEDEVICES,
  WALLPAPER_SETWALLPAPER,
  VIRTUALKEYBOARDPRIVATE_HIDEKEYBOARD,
  AUTOTESTPRIVATE_LOCKSCREEN,
  WEBRTCLOGGINGPRIVATE_SETMETADATA,
  WEBRTCLOGGINGPRIVATE_START,
  WEBRTCLOGGINGPRIVATE_SETUPLOADONRENDERCLOSE,
  WEBRTCLOGGINGPRIVATE_STOP,
  WEBRTCLOGGINGPRIVATE_UPLOAD,
  WEBRTCLOGGINGPRIVATE_DISCARD,
  DELETED_WEBVIEW_OVERRIDEUSERAGENT,
  PRINCIPALSPRIVATE_SHOWAVATARBUBBLE,
  PRINCIPALSPRIVATE_SIGNOUT,
  CAST_CHANNEL_OPEN,
  CAST_CHANNEL_SEND,
  CAST_CHANNEL_CLOSE,
  RUNTIME_RESTART,
  DESKTOPCAPTURE_CANCELCHOOSEDESKTOPMEDIA,
  APP_CURRENTWINDOWINTERNAL_SETALWAYSONTOP,
  SOCKETS_TCP_CREATE,
  SOCKETS_TCP_UPDATE,
  SOCKETS_TCP_SETPAUSED,
  SOCKETS_TCP_SETKEEPALIVE,
  SOCKETS_TCP_SETNODELAY,
  SOCKETS_TCP_CONNECT,
  SOCKETS_TCP_DISCONNECT,
  SOCKETS_TCP_SEND,
  SOCKETS_TCP_CLOSE,
  SOCKETS_TCP_GETINFO,
  SOCKETS_TCP_GETSOCKETS,
  NETWORKINGPRIVATE_GETENABLEDNETWORKTYPES,
  NETWORKINGPRIVATE_ENABLENETWORKTYPE,
  NETWORKINGPRIVATE_DISABLENETWORKTYPE,
  SOCKETS_TCP_SERVER_CREATE,
  SOCKETS_TCP_SERVER_UPDATE,
  SOCKETS_TCP_SERVER_SETPAUSED,
  SOCKETS_TCP_SERVER_LISTEN,
  SOCKETS_TCP_SERVER_DISCONNECT,
  SOCKETS_TCP_SERVER_CLOSE,
  SOCKETS_TCP_SERVER_GETINFO,
  SOCKETS_TCP_SERVER_GETSOCKETS,
  SYSTEM_STORAGE_GETAVAILABLECAPACITY,
  BROWSERACTION_OPEN_POPUP,
  WEBRTC_AUDIO_PRIVATE_GET_SINKS,
  WEBRTC_AUDIO_PRIVATE_GET_ACTIVE_SINK,
  WEBRTC_AUDIO_PRIVATE_SET_ACTIVE_SINK,
  WEBRTC_AUDIO_PRIVATE_GET_ASSOCIATED_SINK,
  VIRTUALKEYBOARDPRIVATE_KEYBOARDLOADED,
  DELETED_APP_CURRENTWINDOWINTERNAL_SETMINWIDTH,
  DELETED_APP_CURRENTWINDOWINTERNAL_SETMINHEIGHT,
  DELETED_APP_CURRENTWINDOWINTERNAL_SETMAXWIDTH,
  DELETED_APP_CURRENTWINDOWINTERNAL_SETMAXHEIGHT,
  SYSTEMPRIVATE_GETAPIKEY,
  CHROMEOSINFOPRIVATE_SET,
  BOOKMARKMANAGERPRIVATE_GETMETAINFO,
  BOOKMARKMANAGERPRIVATE_SETMETAINFO,
  FILESYSTEMPROVIDER_MOUNT,
  AUTOTESTPRIVATE_GETEXTENSIONSINFO,
  SCREENLOCKPRIVATE_GETLOCKED,
  SCREENLOCKPRIVATE_SETLOCKED,
  SCREENLOCKPRIVATE_SHOWMESSAGE,
  FEEDBACKPRIVATE_GETHISTOGRAMS,
  SYSTEM_NETWORK_GETNETWORKINTERFACES,
  SERIAL_GETDEVICES,
  SERIAL_UPDATE,
  SERIAL_SETPAUSED,
  SERIAL_GETINFO,
  SERIAL_GETCONNECTIONS,
  SERIAL_SEND,
  GCM_REGISTER,
  GCM_SEND,
  SERIAL_CONNECT,
  SERIAL_DISCONNECT,
  MEDIAGALLERIES_GETALLMEDIAFILESYSTEMMETADATA,
  FIRSTRUNPRIVATE_GETLOCALIZEDSTRINGS,
  FIRSTRUNPRIVATE_LAUNCHTUTORIAL,
  SOCKETS_UDP_SETPAUSED,
  DELETED_WEBVIEW_CAPTUREVISIBLEREGION,
  MEDIAGALLERIES_GETMETADATA,
  INPUT_IME_SENDKEYEVENTS,
  VIRTUALKEYBOARDPRIVATE_LOCKKEYBOARD,
  SCREENLOCKPRIVATE_SHOWCUSTOMICON,
  INPUT_IME_HIDEINPUTVIEW,
  BOOKMARKMANAGERPRIVATE_UNDO,
  BOOKMARKMANAGERPRIVATE_REDO,
  BOOKMARKMANAGERPRIVATE_UNDOINFO,
  BOOKMARKMANAGERPRIVATE_REDOINFO,
  MEDIAGALLERIES_ADDUSERSELECTEDFOLDER,
  PREFERENCESPRIVATE_GETSYNCCATEGORIESWITHOUTPASSPHRASE,
  READINGLISTPRIVATE_ADDENTRY,
  READINGLISTPRIVATE_REMOVEENTRY,
  READINGLISTPRIVATE_GETENTRIES,
  MEDIAGALLERIES_STARTMEDIASCAN,
  MEDIAGALLERIES_CANCELMEDIASCAN,
  MEDIAGALLERIES_ADDSCANRESULTS,
  LOGPRIVATE_STARTNETINTERNALSWATCH,
  LOGPRIVATE_STOPNETINTERNALSWATCH,
  FILEMANAGERPRIVATE_GETPROFILES,
  DELETED_FILEMANAGERPRIVATE_VISITDESKTOP,
  VIRTUALKEYBOARDPRIVATE_GETKEYBOARDCONFIG,
  HID_GETDEVICES,
  HID_CONNECT,
  HID_DISCONNECT,
  HID_RECEIVE,
  HID_SEND,
  HID_RECEIVEFEATUREREPORT,
  HID_SENDFEATUREREPORT,
  HOTWORDPRIVATE_SETENABLED,
  HOTWORDPRIVATE_GETSTATUS,
  DELETED_APP_CURRENTWINDOWINTERNAL_SETBADGEICON,
  DELETED_APP_CURRENTWINDOWINTERNAL_CLEARBADGE,
  DELETED_WEBVIEW_SETZOOM,
  DELETED_WEBVIEW_GETZOOM,
  DEVELOPERPRIVATE_REQUESTFILESOURCE,
  DEVELOPERPRIVATE_OPENDEVTOOLS,
  ACTIVITYLOGPRIVATE_DELETEACTIVITIES,
  NETWORKINGPRIVATE_SETWIFITDLSENABLEDSTATE,
  NETWORKINGPRIVATE_GETWIFITDLSSTATUS,
  SCREENLOCKPRIVATE_HIDECUSTOMICON,
  SCREENLOCKPRIVATE_SETAUTHTYPE,
  SCREENLOCKPRIVATE_GETAUTHTYPE,
  SCREENLOCKPRIVATE_ACCEPTAUTHATTEMPT,
  DELETED_WEBVIEW_FIND,
  DELETED_WEBVIEW_STOPFINDING,
  DELETED_WEBVIEW_CONTEXTMENUSCREATE,
  DELETED_WEBVIEW_CONTEXTMENUSUPDATE,
  DELETED_WEBVIEW_CONTEXTMENUSREMOVE,
  DELETED_WEBVIEW_CONTEXTMENUSREMOVEALL,
  AUTOMATIONINTERNAL_ENABLETAB,
  APP_CURRENTWINDOWINTERNAL_SETSIZECONSTRAINTS,
  BLUETOOTH_GETDEVICE,
  GCM_UNREGISTER,
  FILEMANAGERPRIVATEINTERNAL_REQUESTDRIVESHARE,
  METRICSPRIVATE_RECORDSPARSEVALUE,
  HOTWORDPRIVATE_SETAUDIOLOGGINGENABLED,
  BLUETOOTHPRIVATE_SETADAPTERSTATE,
  DELETED_BLUETOOTHPRIVATE_ENABLEPAIRING,
  DELETED_BLUETOOTHPRIVATE_DISABLEPAIRING,
  BLUETOOTHPRIVATE_SETPAIRINGRESPONSE,
  NETWORKINGPRIVATE_GETCAPTIVEPORTALSTATUS,
  AUTOMATIONINTERNAL_PERFORMACTION,
  DELETED_BLUETOOTH_UPDATE_SOCKET,
  DELETED_BLUETOOTH_SET_SOCKET_PAUSED,
  DELETED_BLUETOOTH_GET_SOCKET,
  DELETED_BLUETOOTH_GET_SOCKETS,
  FILESYSTEMPROVIDER_UNMOUNT,
  FILESYSTEMPROVIDERINTERNAL_UNMOUNTREQUESTEDSUCCESS,
  DELETED_FILESYSTEMPROVIDERINTERNAL_UNMOUNTREQUESTEDERROR,
  MEDIAGALLERIES_DROPPERMISSIONFORMEDIAFILESYSTEM,
  WEBCAMPRIVATE_SET,
  WEBCAMPRIVATE_RESET,
  WEBCAMPRIVATE_GET,
  BLUETOOTHLOWENERGY_GETSERVICE,
  BLUETOOTHLOWENERGY_GETSERVICES,
  BLUETOOTHLOWENERGY_GETCHARACTERISTIC,
  BLUETOOTHLOWENERGY_GETCHARACTERISTICS,
  BLUETOOTHLOWENERGY_GETINCLUDEDSERVICES,
  BLUETOOTHLOWENERGY_GETDESCRIPTOR,
  BLUETOOTHLOWENERGY_GETDESCRIPTORS,
  BLUETOOTHLOWENERGY_READCHARACTERISTICVALUE,
  BLUETOOTHLOWENERGY_WRITECHARACTERISTICVALUE,
  BLUETOOTHLOWENERGY_READDESCRIPTORVALUE,
  BLUETOOTHLOWENERGY_WRITEDESCRIPTORVALUE,
  BOOKMARKMANAGERPRIVATE_CREATEWITHMETAINFO,
  BOOKMARKMANAGERPRIVATE_UPDATEMETAINFO,
  BLUETOOTHSOCKET_CREATE,
  BLUETOOTHSOCKET_UPDATE,
  BLUETOOTHSOCKET_SETPAUSED,
  BLUETOOTHSOCKET_LISTENUSINGRFCOMM,
  BLUETOOTHSOCKET_LISTENUSINGINSECURERFCOMM,
  BLUETOOTHSOCKET_LISTENUSINGL2CAP,
  BLUETOOTHSOCKET_CONNECT,
  BLUETOOTHSOCKET_DISCONNECT,
  BLUETOOTHSOCKET_CLOSE,
  BLUETOOTHSOCKET_SEND,
  BLUETOOTHSOCKET_GETINFO,
  BLUETOOTHSOCKET_GETSOCKETS,
  DELETED_WEBSTOREPRIVATE_SIGNINFUNCTION,
  DELETED_SHELL_CREATEWINDOW,
  FILESYSTEMPROVIDERINTERNAL_GETMETADATAREQUESTEDSUCCESS,
  DELETED_FILESYSTEMPROVIDERINTERNAL_GETMETADATAREQUESTEDERROR,
  BROWSER_OPENTAB,
  MANAGEMENT_CREATEAPPSHORTCUT,
  DELETED_WEBVIEW_SHOWCONTEXTMENU,
  WEBRTCLOGGINGPRIVATE_STARTRTPDUMP,
  WEBRTCLOGGINGPRIVATE_STOPRTPDUMP,
  AUTOMATIONINTERNAL_ENABLEDESKTOP,
  HOTWORDPRIVATE_SETHOTWORDSESSIONSTATE,
  HOTWORDPRIVATE_NOTIFYHOTWORDRECOGNITION,
  FILESYSTEMPROVIDERINTERNAL_READDIRECTORYREQUESTEDSUCCESS,
  DELETED_FILESYSTEMPROVIDERINTERNAL_READDIRECTORYREQUESTEDERROR,
  DELETED_LEDGER_BATCHEXECUTE,
  DELETED_FILESYSTEMPROVIDERINTERNAL_OPENFILEREQUESTEDSUCCESS,
  DELETED_FILESYSTEMPROVIDERINTERNAL_OPENFILEREQUESTEDERROR,
  DELETED_FILESYSTEMPROVIDERINTERNAL_CLOSEFILEREQUESTEDSUCCESS,
  DELETED_FILESYSTEMPROVIDERINTERNAL_CLOSEFILEREQUESTEDERROR,
  DELETED_SYNCEDNOTIFICATIONSPRIVATE_GETINITIALDATA,
  DELETED_SYNCEDNOTIFICATIONSPRIVATE_UPDATENOTIFICATION,
  DELETED_SYNCEDNOTIFICATIONSPRIVATE_SETRENDERCONTEXT,
  IDENTITY_GETACCOUNTS,
  FILEMANAGERPRIVATE_RESOLVEISOLATEDENTRIES,
  FILESYSTEMPROVIDERINTERNAL_READFILEREQUESTEDSUCCESS,
  DELETED_FILESYSTEMPROVIDERINTERNAL_READFILEREQUESTEDERROR,
  NETWORKINGPRIVATE_GETNETWORKS,
  DELETED_WEBVIEW_SETNAME,
  ENTERPRISE_PLATFORMKEYSINTERNAL_GENERATEKEY,
  PLATFORMKEYSINTERNAL_SIGN,
  ENTERPRISE_PLATFORMKEYSINTERNAL_GETTOKENS,
  ENTERPRISE_PLATFORMKEYS_GETCERTIFICATES,
  ENTERPRISE_PLATFORMKEYS_IMPORTCERTIFICATE,
  ENTERPRISE_PLATFORMKEYS_REMOVECERTIFICATE,
  FILEMANAGERPRIVATE_OPENINSPECTOR,
  STREAMSPRIVATE_ABORT,
  MANAGEMENT_SETLAUNCHTYPE,
  MANAGEMENT_GENERATEAPPFORLINK,
  DELETED_GUESTVIEWINTERNAL_ALLOCATEINSTANCEID,
  DELETED_WEBVIEW_NAVIGATE,
  INPUTMETHODPRIVATE_GETCURRENTINPUTMETHOD,
  INPUTMETHODPRIVATE_SETCURRENTINPUTMETHOD,
  INPUTMETHODPRIVATE_GETINPUTMETHODS,
  IDENTITY_GETPROFILEUSERINFO,
  VIRTUALKEYBOARDPRIVATE_OPENSETTINGS,
  BLUETOOTHLOWENERGY_CONNECT,
  BLUETOOTHLOWENERGY_DISCONNECT,
  WEBSTOREPRIVATE_GETEPHEMERALAPPSENABLED,
  WEBSTOREPRIVATE_LAUNCHEPHEMERALAPP,
  FILESYSTEMPROVIDERINTERNAL_OPERATIONREQUESTEDERROR,
  FILESYSTEMPROVIDERINTERNAL_OPERATIONREQUESTEDSUCCESS,
  GUESTVIEWINTERNAL_CREATEGUEST,
  WEBVIEWINTERNAL_CAPTUREVISIBLEREGION,
  WEBVIEWINTERNAL_CONTEXTMENUSCREATE,
  WEBVIEWINTERNAL_CONTEXTMENUSREMOVE,
  WEBVIEWINTERNAL_CONTEXTMENUSREMOVEALL,
  WEBVIEWINTERNAL_CONTEXTMENUSUPDATE,
  WEBVIEWINTERNAL_CLEARDATA,
  WEBVIEWINTERNAL_EXECUTESCRIPT,
  WEBVIEWINTERNAL_FIND,
  WEBVIEWINTERNAL_GETZOOM,
  WEBVIEWINTERNAL_GO,
  WEBVIEWINTERNAL_INSERTCSS,
  WEBVIEWINTERNAL_NAVIGATE,
  WEBVIEWINTERNAL_OVERRIDEUSERAGENT,
  WEBVIEWINTERNAL_RELOAD,
  WEBVIEWINTERNAL_SETNAME,
  WEBVIEWINTERNAL_SETPERMISSION,
  WEBVIEWINTERNAL_SETZOOM,
  WEBVIEWINTERNAL_SHOWCONTEXTMENU,
  WEBVIEWINTERNAL_STOP,
  WEBVIEWINTERNAL_STOPFINDING,
  WEBVIEWINTERNAL_TERMINATE,
  BLUETOOTHLOWENERGY_STARTCHARACTERISTICNOTIFICATIONS,
  BLUETOOTHLOWENERGY_STOPCHARACTERISTICNOTIFICATIONS,
  GCDPRIVATE_GETCLOUDDEVICELIST,
  GCDPRIVATE_QUERYFORNEWLOCALDEVICES,
  GCDPRIVATE_PREFETCHWIFIPASSWORD,
  GCDPRIVATE_ESTABLISHSESSION,
  GCDPRIVATE_SENDMESSAGE,
  GCDPRIVATE_CONFIRMCODE,
  GCDPRIVATE_TERMINATESESSION,
  TABS_SETZOOM,
  TABS_GETZOOM,
  TABS_SETZOOMSETTINGS,
  TABS_GETZOOMSETTINGS,
  GCDPRIVATE_GETCOMMANDDEFINITIONS,
  GCDPRIVATE_INSERTCOMMAND,
  GCDPRIVATE_GETCOMMAND,
  GCDPRIVATE_CANCELCOMMAND,
  GCDPRIVATE_GETCOMMANDSLIST,
  APPVIEWINTERNAL_ATTACHFRAME,
  APPVIEWINTERNAL_DENYREQUEST,
  FILEMANAGERPRIVATEINTERNAL_GETDOWNLOADURL,
  EASYUNLOCKPRIVATE_PERFORMECDHKEYAGREEMENT,
  EASYUNLOCKPRIVATE_GENERATEECP256KEYPAIR,
  EASYUNLOCKPRIVATE_CREATESECUREMESSAGE,
  EASYUNLOCKPRIVATE_UNWRAPSECUREMESSAGE,
  LOGPRIVATE_STARTEVENTRECODER,
  LOGPRIVATE_STOPEVENTRECODER,
  LOGPRIVATE_DUMPLOGS,
  SOCKET_SECURE,
  SOCKETS_TCP_SECURE,
  EXPERIENCESAMPLINGPRIVATE_GETBROWSERINFO,
  EASYUNLOCKPRIVATE_SEEKBLUETOOTHDEVICEBYADDRESS,
  EASYUNLOCKPRIVATE_GETSTRINGS,
  NOTIFICATIONPROVIDER_SENDONCLEAR,
  NOTIFICATIONPROVIDER_NOTIFYONCLEARED,
  NOTIFICATIONPROVIDER_NOTIFYONCLICKED,
  NOTIFICATIONPROVIDER_NOTIFYONBUTTONCLICKED,
  NOTIFICATIONPROVIDER_NOTIFYONPERMISSIONLEVELCHANGED,
  NOTIFICATIONPROVIDER_NOTIFYONSHOWSETTINGS,
  NOTIFICATIONPROVIDER_GETNOTIFIER,
  NOTIFICATIONPROVIDER_GETALLNOTIFIERS,
  GCDPRIVATE_GETPREFETCHEDWIFINAMELIST,
  GUESTVIEWINTERNAL_SETAUTOSIZE,
  COPRESENCEPRIVATE_SENDFOUND,
  COPRESENCEPRIVATE_SENDSAMPLES,
  COPRESENCEPRIVATE_SENDDETECT,
  COPRESENCEPRIVATE_SENDINITIALIZED,
  COPRESENCE_EXECUTE,
  COPRESENCE_SETAPIKEY,
  FILESYSTEM_OBSERVEDIRECTORY,
  FILESYSTEM_UNOBSERVEENTRY,
  FILESYSTEM_GETOBSERVEDENTRIES,
  BROWSINGDATA_REMOVESERVICEWORKERS,
  USBPRIVATE_GETDEVICES,
  USBPRIVATE_GETDEVICEINFO,
  EASYUNLOCKPRIVATE_UPDATESCREENLOCKSTATE,
  CAST_CHANNEL_GETLOGS,
  EASYUNLOCKPRIVATE_SETPERMITACCESS,
  EASYUNLOCKPRIVATE_GETPERMITACCESS,
  EASYUNLOCKPRIVATE_CLEARPERMITACCESS,
  EASYUNLOCKPRIVATE_SETREMOTEDEVICES,
  EASYUNLOCKPRIVATE_GETREMOTEDEVICES,
  FILESYSTEMPROVIDER_GETALL,
  EASYUNLOCKPRIVATE_CONNECTTOBLUETOOTHSERVICEINSECURELY,
  MEDIAGALLERIES_ADDGALLERYWATCH,
  MEDIAGALLERIES_REMOVEGALLERYWATCH,
  MEDIAGALLERIES_GETALLGALLERYWATCH,
  MEDIAGALLERIES_REMOVEALLGALLERYWATCH,
  MANAGEMENT_GETSELF,
  APP_CURRENTWINDOWINTERNAL_SETVISIBLEONALLWORKSPACES,
  EASYUNLOCKPRIVATE_GETSIGNINCHALLENGE,
  EASYUNLOCKPRIVATE_TRYSIGNINSECRET,
  ACCESSIBILITY_PRIVATE_SETFOCUSRING,
  USB_GETCONFIGURATION,
  WEBVIEWINTERNAL_SETALLOWTRANSPARENCY,
  EASYUNLOCKPRIVATE_GETUSERINFO,
  HOTWORDPRIVATE_GETLAUNCHSTATE,
  HOTWORDPRIVATE_SETHOTWORDALWAYSONSEARCHENABLED,
  WEBVIEWINTERNAL_LOADDATAWITHBASEURL,
  GUESTVIEWINTERNAL_DESTROYGUEST,
  DELETED_COPRESENCESOCKET_CREATEPEER,
  DELETED_COPRESENCESOCKET_DESTROYPEER,
  DELETED_COPRESENCESOCKET_SEND,
  DELETED_COPRESENCESOCKET_DISCONNECT,
  BOOKMARKMANAGERPRIVATE_SETVERSION,
  FILESYSTEMPROVIDER_NOTIFY,
  USB_GETUSERSELECTEDDEVICES,
  INPUTMETHODPRIVATE_GETINPUTMETHODCONFIG,
  WALLPAPERPRIVATE_GETSYNCSETTING,
  COPRESENCE_SETAUTHTOKEN,
  CAST_CHANNEL_SETAUTHORITYKEYS,
  HOTWORDPRIVATE_STARTTRAINING,
  HOTWORDPRIVATE_FINALIZESPEAKERMODEL,
  HOTWORDPRIVATE_STOPTRAINING,
  GCDPRIVATE_STARTPAIRING,
  VPNPROVIDER_CREATECONFIG,
  VPNPROVIDER_DESTROYCONFIG,
  VPNPROVIDER_SETPARAMETERS,
  VPNPROVIDER_SENDPACKET,
  VPNPROVIDER_NOTIFYCONNECTIONSTATECHANGED,
  DOCUMENT_SCAN_SCAN,
  DELETED_EASYUNLOCKPRIVATE_GETUSERIMAGE,
  HOTWORDPRIVATE_NOTIFYSPEAKERMODELSAVED,
  HOTWORDPRIVATE_GETLOCALIZEDSTRINGS,
  HOTWORDPRIVATE_SETAUDIOHISTORYENABLED,
  HOTWORDPRIVATE_GETAUDIOHISTORYENABLED,
  DELETED_APP_CURRENTWINDOWINTERNAL_SETINTERCEPTALLKEYS,
  LAUNCHERPAGE_PUSHSUBPAGE,
  LAUNCHERPAGE_SHOW,
  AUTOTESTPRIVATE_SETTOUCHPADSENSITIVITY,
  AUTOTESTPRIVATE_SETTAPTOCLICK,
  AUTOTESTPRIVATE_SETTHREEFINGERCLICK,
  AUTOTESTPRIVATE_SETTAPDRAGGING,
  AUTOTESTPRIVATE_SETNATURALSCROLL,
  AUTOTESTPRIVATE_SETMOUSESENSITIVITY,
  AUTOTESTPRIVATE_SETPRIMARYBUTTONRIGHT,
  DELETED_COPRESENCEENDPOINTS_CREATELOCALENDPOINT,
  DELETED_COPRESENCEENDPOINTS_DESTROYLOCALENDPOINT,
  DELETED_COPRESENCEENDPOINTS_SEND,
  INLINE_INSTALL_PRIVATE_INSTALL,
  LAUNCHERPAGE_SETENABLED,
  DELETED_CRYPTOTOKENPRIVATE_REQUESTPERMISSION,
  BLUETOOTHPRIVATE_DISCONNECTALL,
  FILEMANAGERPRIVATEINTERNAL_GETMIMETYPE,
  USB_SETCONFIGURATION,
  EASYUNLOCKPRIVATE_GETCONNECTIONINFO,
  FILEMANAGERPRIVATEINTERNAL_COMPUTECHECKSUM,
  PRINTERPROVIDERINTERNAL_REPORTPRINTRESULT,
  PRINTERPROVIDERINTERNAL_REPORTPRINTERCAPABILITY,
  PRINTERPROVIDERINTERNAL_REPORTPRINTERS,
  FILESYSTEMPROVIDER_GET,
  FILEMANAGERPRIVATE_SEARCHFILESBYHASHES,
  EASYUNLOCKPRIVATE_SHOWERRORBUBBLE,
  EXTENSIONVIEWINTERNAL_NAVIGATE,
  NETWORKING_CONFIG_SETNETWORKFILTER,
  NETWORKING_CONFIG_FINISHAUTHENTICATION,
  PLATFORMKEYSINTERNAL_SELECTCLIENTCERTIFICATES,
  CRYPTOTOKENPRIVATE_CANORIGINASSERTAPPID,
  EASYUNLOCKPRIVATE_SETAUTOPAIRINGRESULT,
  FILEMANAGERPRIVATE_ISUMAENABLED,
  WEBVIEWINTERNAL_SETALLOWSCALING,
  PLATFORMKEYSINTERNAL_GETPUBLICKEY,
  RUNTIME_OPENOPTIONSPAGE,
  AUDIOMODEM_TRANSMIT,
  AUDIOMODEM_STOPTRANSMIT,
  AUDIOMODEM_RECEIVE,
  AUDIOMODEM_STOPRECEIVE,
  WEBRTCLOGGINGPRIVATE_STORE,
  WEBRTCLOGGINGPRIVATE_UPLOADSTORED,
  FILEMANAGERPRIVATEINTERNAL_SETENTRYTAG,
  INPUTMETHODPRIVATE_FETCHALLDICTIONARYWORDS,
  INPUTMETHODPRIVATE_ADDWORDTODICTIONARY,
  DASHBOARDPRIVATE_SHOWPERMISSIONPROMPTFORDELEGATEDINSTALL,
  PRINTERPROVIDERINTERNAL_GETPRINTDATA,
  VIRTUALKEYBOARDPRIVATE_SETMODE,
  NETWORKINGPRIVATE_STARTACTIVATE,
  FILEMANAGERPRIVATE_GRANTACCESS,
  DEVELOPERPRIVATE_GETEXTENSIONSINFO,
  DEVELOPERPRIVATE_GETEXTENSIONINFO,
  FILEMANAGERPRIVATE_ENABLEEXTERNALFILESCHEME,
  DEVELOPERPRIVATE_UPDATEEXTENSIONCONFIGURATION,
  DEVELOPERPRIVATE_DELETEEXTENSIONERRORS,
  FILEMANAGERPRIVATE_ISPIEXLOADERENABLED,
  HOTWORDPRIVATE_SPEAKERMODELEXISTSRESULT,
  SETTINGSPRIVATE_SETPREF,
  DELETED_SETTINGSPRIVATE_SETDOUBLEPREF,
  DELETED_SETTINGSPRIVATE_SETSTRINGPREF,
  DELETED_SETTINGSPRIVATE_SETURLPREF,
  SETTINGSPRIVATE_GETALLPREFS,
  SETTINGSPRIVATE_GETPREF,
  NETWORKINGPRIVATE_FORGETNETWORK,
  EASYUNLOCKPRIVATE_HIDEERRORBUBBLE,
  WEBVIEWINTERNAL_SETZOOMMODE,
  WEBVIEWINTERNAL_GETZOOMMODE,
  LAUNCHERSEARCHPROVIDER_SETSEARCHRESULTS,
  DATAREDUCTIONPROXY_CLEARDATASAVINGS,
  BLUETOOTHPRIVATE_SETDISCOVERYFILTER,
  FILESYSTEM_GETVOLUMELIST,
  NETWORKINGPRIVATE_GETDEVICESTATES,
  DEVELOPERPRIVATE_GETPROFILECONFIGURATION,
  DEVELOPERPRIVATE_UPDATEPROFILECONFIGURATION,
  SOCKETS_UDP_SETBROADCAST,
  FILEMANAGERPRIVATE_GETPROVIDINGEXTENSIONS,
  WEBVIEWINTERNAL_ADDCONTENTSCRIPTS,
  WEBVIEWINTERNAL_REMOVECONTENTSCRIPTS,
  DEVELOPERPRIVATE_REPAIREXTENSION,
  DEVELOPERPRIVATE_SHOWOPTIONS,
  DEVELOPERPRIVATE_SHOWPATH,
  FILEMANAGERPRIVATE_ADDPROVIDEDFILESYSTEM,
  FILEMANAGERPRIVATE_CONFIGUREVOLUME,
  SEARCHENGINESPRIVATE_GETSEARCHENGINES,
  SEARCHENGINESPRIVATE_SETSELECTEDSEARCHENGINE,
  AUTOFILLPRIVATE_SAVEADDRESS,
  AUTOFILLPRIVATE_GETADDRESSCOMPONENTS,
  AUTOFILLPRIVATE_SAVECREDITCARD,
  AUTOFILLPRIVATE_REMOVEENTRY,
  AUTOFILLPRIVATE_VALIDATEPHONENUMBERS,
  AUTOFILLPRIVATE_MASKCREDITCARD,
  INSTANCEID_GETID,
  INSTANCEID_GETCREATIONTIME,
  INSTANCEID_GETTOKEN,
  INSTANCEID_DELETETOKEN,
  INSTANCEID_DELETEID,
  GCDPRIVATE_GETDEVICEINFO,
  SEARCHENGINESPRIVATE_GETHOTWORDSTATE,
  SEARCHENGINESPRIVATE_ADDOTHERSEARCHENGINE,
  SEARCHENGINESPRIVATE_REMOVESEARCHENGINE,
  SEARCHENGINESPRIVATE_UPDATESEARCHENGINE,
  SEARCHENGINESPRIVATE_OPTINTOHOTWORDING,
  WEBSTOREWIDGETPRIVATE_INSTALLWEBSTOREITEM,
  WEBSTOREWIDGETPRIVATE_GETSTRINGS,
  WEBRTCDESKTOPCAPTUREPRIVATE_CHOOSEDESKTOPMEDIA,
  WEBRTCDESKTOPCAPTUREPRIVATE_CANCELCHOOSEDESKTOPMEDIA,
  BLUETOOTHLOWENERGY_REGISTERADVERTISEMENT,
  BLUETOOTHLOWENERGY_UNREGISTERADVERTISEMENT,
  PASSWORDSPRIVATE_CANPASSWORDACCOUNTBEMANAGED,
  PASSWORDSPRIVATE_REMOVESAVEDPASSWORD,
  PASSWORDSPRIVATE_REMOVEPASSWORDEXCEPTION,
  PASSWORDSPRIVATE_REQUESTPLAINTEXTPASSWORD,
  LAUNCHERPAGE_HIDE,
  PLATFORMKEYS_VERIFYTLSSERVERCERTIFICATE,
  DEVELOPERPRIVATE_SETSHORTCUTHANDLINGSUSPENDED,
  DEVELOPERPRIVATE_UPDATEEXTENSIONCOMMAND,
  INPUTMETHODPRIVATE_GETENCRYPTSYNCENABLED,
  USERSPRIVATE_GETWHITELISTEDUSERS,
  USERSPRIVATE_ADDWHITELISTEDUSER,
  USERSPRIVATE_REMOVEWHITELISTEDUSER,
  USERSPRIVATE_ISCURRENTUSEROWNER,
  USERSPRIVATE_ISWHITELISTMANAGED,
  PRINTERPROVIDERINTERNAL_REPORTUSBPRINTERINFO,
  WEBCAMPRIVATE_OPENSERIALWEBCAM,
  WEBCAMPRIVATE_CLOSEWEBCAM,
  SERIAL_SETBREAK,
  SERIAL_CLEARBREAK,
  EXTENSIONVIEWINTERNAL_LOADSRC,
  EXTENSIONVIEWINTERNAL_PARSESRC,
  HID_GETUSERSELECTEDDEVICES,
  FILESYSTEMPROVIDERINTERNAL_GETACTIONSREQUESTEDSUCCESS,
  DASHBOARDPRIVATE_SHOWPERMISSIONPROMPTFORDELEGATEDBUNDLEINSTALL,
  FILEMANAGERPRIVATEINTERNAL_GETCUSTOMACTIONS,
  FILEMANAGERPRIVATEINTERNAL_EXECUTECUSTOMACTION,
  MDNS_FORCEDISCOVERY,
  LANGUAGESETTINGSPRIVATE_GETLANGUAGELIST,
  LANGUAGESETTINGSPRIVATE_SETLANGUAGELIST,
  LANGUAGESETTINGSPRIVATE_GETSPELLCHECKDICTIONARYSTATUS,
  LANGUAGESETTINGSPRIVATE_GETSPELLCHECKWORDS,
  LANGUAGESETTINGSPRIVATE_GETTRANSLATETARGETLANGUAGE,
  LANGUAGESETTINGSPRIVATE_GETINPUTMETHODLISTS,
  LANGUAGESETTINGSPRIVATE_ADDINPUTMETHOD,
  LANGUAGESETTINGSPRIVATE_REMOVEINPUTMETHOD,
  FILEMANAGERPRIVATE_CANCELALLFILETRANSFERS,
  NETWORKINGPRIVATE_UNLOCKCELLULARSIM,
  NETWORKINGPRIVATE_SETCELLULARSIMSTATE,
  ENTERPRISE_DEVICEATTRIBUTES_GETDIRECTORYDEVICEID,
  CASTDEVICESPRIVATE_UPDATEDEVICES,
  SYSTEM_DISPLAY_ENABLEUNIFIEDDESKTOP,
  BROWSINGDATA_REMOVECACHESTORAGE,
  VIRTUALKEYBOARDPRIVATE_SETKEYBOARDSTATE,
  VIRTUALKEYBOARDPRIVATE_SETHOTRODKEYBOARD,
  CERTIFICATEPROVIDERINTERNAL_REPORTSIGNATURE,
  CERTIFICATEPROVIDERINTERNAL_REPORTCERTIFICATES,
  BLUETOOTHPRIVATE_PAIR,
  EASYUNLOCKPRIVATE_FINDSETUPCONNECTION,
  RESOURCESPRIVATE_GETSTRINGS,
  USB_GETCONFIGURATIONS,
  EASYUNLOCKPRIVATE_SETUPCONNECTIONSTATUS,
  EASYUNLOCKPRIVATE_SETUPCONNECTIONDISCONNECT,
  EASYUNLOCKPRIVATE_SETUPCONNECTIONSEND,
  DATAREDUCTIONPROXY_GETDATAUSAGE,
  EASYUNLOCKPRIVATE_SETUPCONNECTIONGETDEVICEADDRESS,
  TABCAPTURE_CAPTUREOFFSCREENTAB,
  // Last entry: Add new entries above, then run:
  // python tools/metrics/histograms/update_extension_histograms.py
  ENUM_BOUNDARY
};

}  // namespace functions
}  // namespace extensions

#endif  // EXTENSIONS_BROWSER_EXTENSION_FUNCTION_HISTOGRAM_VALUE_H_
