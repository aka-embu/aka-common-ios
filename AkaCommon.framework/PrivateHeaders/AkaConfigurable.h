//
//  AkaConfigurable.h
//  AkaCommon
//
//  Created by Brian Salomon on 3/4/19.
//  Copyright © 2019 Akamai Technologies, Inc. All rights reserved.
//

#ifndef AkaConfigurable_h
#define AkaConfigurable_h

#import <UIKit/UIKit.h>

//TODO private protocol

/**
 * Interface for all SDK classes that need load-time configuration.
 */
@protocol AkaConfigurable <NSObject>

/**
 * Called when app issues [AkaCommon configure].
 */
+ (void)configureWithOptions:(nullable NSDictionary *)options;

/**
 * Return a class instance to handle messages from Common SDK.
 */
+ (nonnull instancetype)shared;

@optional

/**
 * Push messages are passed to the framework if this is implemented.
 * These are called on the SDK queue.
 *
 * Return YES if the notification is handled. If YES is returned, the fetch
 * completion handler should be called by the framework when processing is
 * complete.
 */
- (BOOL)didReceiveRemoteNotification:(nullable NSDictionary*)userInfo
			  fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))handler;

@end

#endif /* AkaConfigurable_h */
