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

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AkaLoggerName NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AkaLoggerName const AkaLoggerNameASL NS_SWIFT_NAME(AkaLoggerName.asl); // DDASLLogger
FOUNDATION_EXPORT AkaLoggerName const AkaLoggerNameTTY NS_SWIFT_NAME(AkaLoggerName.tty); // DDTTYLogger
FOUNDATION_EXPORT AkaLoggerName const AkaLoggerNameOS NS_SWIFT_NAME(AkaLoggerName.os); // DDOSLogger
FOUNDATION_EXPORT AkaLoggerName const AkaLoggerNameFile NS_SWIFT_NAME(AkaLoggerName.file); // DDFileLogger

NS_ASSUME_NONNULL_END
