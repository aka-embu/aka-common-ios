//
//  AkaLogger.h
//  AkaCommon
//
//  Created by Brian Salomon on 3/13/19.
//  Copyright © 2019 Akamai Technologies, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AkaFileLogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface AkaLogFileManager : AkaLogFileManagerDefault
@end

// Notification sent when a new log file is created.
extern NSString * __nonnull const AkaLoggerNewLogFileCreatedNotification;

@interface AkaLogger : NSObject

// Swift convenience functions. ObjC can use AkaLogDebug(), etc. macros.
+ (void)logError:(NSString *)message;
+ (void)logWarn:(NSString *)message;
+ (void)logInfo:(NSString *)message;
+ (void)logDebug:(NSString *)message;
+ (void)logVerbose:(NSString *)message;

// Convenience to create logs before they are lazy-loaded on first access.
+ (void)configure;

@end

NS_ASSUME_NONNULL_END
