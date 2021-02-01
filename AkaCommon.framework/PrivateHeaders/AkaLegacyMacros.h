// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2019, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

/**
 * Legacy macros used for 1.9.x backwards compatibility.
 *
 * Imported by default when importing a DDLog.h directly and DD_LEGACY_MACROS is not defined and set to 0.
 **/
#if Aka_LEGACY_MACROS

#warning CocoaLumberjack 1.9.x legacy macros enabled. \
Disable legacy macros by importing CocoaLumberjack.h or DDLogMacros.h instead of DDLog.h or add `#define Aka_LEGACY_MACROS 0` before importing DDLog.h.

#ifndef AKA_LOG_LEVEL_DEF
    #define AKA_LOG_LEVEL_DEF akaLogLevel
#endif

#define AKA_LOG_FLAG_ERROR    AkaLogFlagError
#define AKA_LOG_FLAG_WARN     AkaLogFlagWarning
#define AKA_LOG_FLAG_INFO     AkaLogFlagInfo
#define AKA_LOG_FLAG_DEBUG    AkaLogFlagDebug
#define AKA_LOG_FLAG_VERBOSE  AkaLogFlagVerbose

#define AKA_LOG_LEVEL_OFF     AkaLogLevelOff
#define AKA_LOG_LEVEL_ERROR   AkaLogLevelError
#define AKA_LOG_LEVEL_WARN    AkaLogLevelWarning
#define AKA_LOG_LEVEL_INFO    AkaLogLevelInfo
#define AKA_LOG_LEVEL_DEBUG   AkaLogLevelDebug
#define AKA_LOG_LEVEL_VERBOSE AkaLogLevelVerbose
#define AKA_LOG_LEVEL_ALL     AkaLogLevelAll

#define AKA_LOG_ASYNC_ENABLED YES

#define AKA_LOG_ASYNC_ERROR    ( NO && AKA_LOG_ASYNC_ENABLED)
#define AKA_LOG_ASYNC_WARN     (YES && AKA_LOG_ASYNC_ENABLED)
#define AKA_LOG_ASYNC_INFO     (YES && AKA_LOG_ASYNC_ENABLED)
#define AKA_LOG_ASYNC_DEBUG    (YES && AKA_LOG_ASYNC_ENABLED)
#define AKA_LOG_ASYNC_VERBOSE  (YES && AKA_LOG_ASYNC_ENABLED)

#define AKA_LOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
       [AkaLog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

#define AKA_LOG_MAYBE(async, lvl, flg, ctx, fnct, frmt, ...)                       \
        do { if(lvl & flg) AKA_LOG_MACRO(async, lvl, flg, ctx, nil, fnct, frmt, ##__VA_ARGS__); } while(0)

#define AKA_LOG_OBJC_MAYBE(async, lvl, flg, ctx, frmt, ...) \
        AKA_LOG_MAYBE(async, lvl, flg, ctx, __PRETTY_FUNCTION__, frmt, ## __VA_ARGS__)

#define AkaLogError(frmt, ...)   AKA_LOG_OBJC_MAYBE(AKA_LOG_ASYNC_ERROR,   AKA_LOG_LEVEL_DEF, AKA_LOG_FLAG_ERROR,   0, frmt, ##__VA_ARGS__)
#define AkaLogWarn(frmt, ...)    AKA_LOG_OBJC_MAYBE(AKA_LOG_ASYNC_WARN,    AKA_LOG_LEVEL_DEF, AKA_LOG_FLAG_WARN,    0, frmt, ##__VA_ARGS__)
#define AkaLogInfo(frmt, ...)    AKA_LOG_OBJC_MAYBE(AKA_LOG_ASYNC_INFO,    AKA_LOG_LEVEL_DEF, AKA_LOG_FLAG_INFO,    0, frmt, ##__VA_ARGS__)
#define AkaLogDebug(frmt, ...)   AKA_LOG_OBJC_MAYBE(AKA_LOG_ASYNC_DEBUG,   AKA_LOG_LEVEL_DEF, AKA_LOG_FLAG_DEBUG,   0, frmt, ##__VA_ARGS__)
#define AkaLogVerbose(frmt, ...) AKA_LOG_OBJC_MAYBE(AKA_LOG_ASYNC_VERBOSE, AKA_LOG_LEVEL_DEF, AKA_LOG_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)

#endif
