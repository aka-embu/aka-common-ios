//
//  AkaCommon.h
//  AkaCommon
//
//  Created by Brian Salomon on 3/1/19.
//  Copyright © 2019 Akamai Technologies, Inc. All rights reserved.
//

#ifndef AkaCommon_h
#define AkaCommon_h

#import <UIKit/UIKit.h>
#include <Foundation/Foundation.h>

//! Project version number for AkaCommon.
FOUNDATION_EXPORT double AkaCommonVersionNumber;

//! Project version string for AkaCommon.
FOUNDATION_EXPORT const unsigned char AkaCommonVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AkaCommon/PublicHeader.h>



@protocol AkaConfigurable;


@protocol AkaCommonDelegate <NSObject>

@optional

/*!
 @brief Invoked when AkaCommon SDK receives a server trust challenge.

 @discussion This optional method allows the app to approve or disallow connections when posed a server trust challenge.
 If this callback is not implemented, the SDK will perform default trust handling (i.e., using trusted authorities on
 the device).

 @note If this function is implemented, 'completionHandler' must be called before it exits.

 @param originalRequest The request made by your app. Its hostname should match the 'modifiedTrust'.
 @param currentRequest A modified request made by the SDK. This may have its hostname resolved to an IP address.
 @param challenge The server trust challenge. The protectionSpace hostname and serverTrust object may have their
 hostnames resolved to an IP address. For this reason, use 'modifiedTrust' when performing trust checks instead
 of 'challenge.protectionSpace.serverTrust'.
 @param modifiedTrust A copy of 'challenge.protectionSpace.serverTrust', currently unmodified. This may be used in
 the future.
 @param completion A block indicating whether the SDK should proceed with or cancel the request. Its parameters
 follow the same rules as NSURLSession::didReceiveChallenge.
 */
- (void)didReceiveChallengeForRequest:(nonnull NSURLRequest *)originalRequest
					   currentRequest:(nonnull NSURLRequest *)currentRequest
							challenge:(nonnull NSURLAuthenticationChallenge *)challenge
						modifiedTrust:(nullable SecTrustRef)modifiedTrust
						   completion:(nonnull void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completion;

@end


/**
 * A class instantiating the core instance through which app accesses the SDK.
 */
@interface AkaCommon : NSObject
{
}

#pragma mark Public

/**
 * Enable printing debug logs to the developer console.
 */
@property (nonatomic, assign) BOOL debugConsoleEnabled;

/**
 * Optional delegate to receive AkaCommon callbacks.
 */
@property (nonatomic, nullable, weak) id<AkaCommonDelegate> delegate;

/**
 * Get shared Mobile SDK Common instance.
 */
+ (nonnull instancetype)shared;

/**
 * Initializes the Mobile SDK Common shared instance and configures each
 * imported Akamai SDK framework. It should be called early in every app
 * run, such as in -didFinishLaunchingWithOptions, before any SDK is used.
 *
 * Safe to call from any thread.
 *
 * This calls each Akamai framework's +configureWithOptions on the main
 * thread and passes that SDK its corresponding options dictionary from
 * the app's Info.plist file.
 */
+ (void)configure;

/**
 * Pass a remote notification from your app to the Mobile SDK.
 *
 * Returns YES if consumed by the SDK (the fetch completion handler will be called).
 * If NO, the app should continue processing the message and call the fetch completion
 * handler itself.
 *
 * The fetchCompletionHandler is run on the main/UI queue.
 */
- (BOOL)didReceiveRemoteNotification:(nullable NSDictionary *)userInfo
			  fetchCompletionHandler:(nonnull void(^)(UIBackgroundFetchResult))handler;

/**
 * Add AkaInterceptor as primary protocol handler, followed by pre-existing handlers.
 */
- (void)interceptSessionsWithConfiguration:(nonnull NSURLSessionConfiguration *)sessionConfig;

/**
 * Print to the console if debugConsoleEnabled.
 */
- (void)debugConsolePrint:(nullable NSString *)logString;

#pragma mark Internal

/**
 * Register an internal SDK with Common framework to receive lifecycle events.
 * This includes initial configuration and any events passed through Common.
 */
+ (void)registerSDK:(nonnull Class<AkaConfigurable>)klass withName:(nonnull NSString*)name;

@end

#endif /* AkaCommon_h */
