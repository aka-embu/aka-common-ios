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

#import <Foundation/Foundation.h>

// Disable legacy macros
#ifndef Aka_LEGACY_MACROS
    #define Aka_LEGACY_MACROS 0
#endif

#import "AkaLog.h"

/**
 * This class provides a logger for the Apple os_log facility.
 **/
API_AVAILABLE(macos(10.12), ios(10.0), watchos(3.0), tvos(10.0))
@interface AkaOSLogger : AkaAbstractLogger <AkaLogger>

/**
 *  Singleton method
 *
 *  @return the shared instance
 */
@property (class, readonly, strong) AkaOSLogger *sharedInstance;

@end
