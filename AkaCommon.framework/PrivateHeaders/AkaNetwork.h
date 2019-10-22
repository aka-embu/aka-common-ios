//
//  AkaNetwork.h
//  AkaCommon
//
//  Created by Brian Salomon on 4/25/19.
//  Copyright © 2019 Akamai Technologies, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AkaInterceptor;

/**
 * An AkaInterceptRequester class makes a network request for the SDK.
 * It is automatically an interceptor handler since it is the class
 * that initiates all Handler callbacks.  Other classes wanting
 * callbacks need to register as handlers.
 */
@protocol AkaInterceptRequester <NSObject>

+ (BOOL)canHandleRequest:(nonnull NSURLRequest*)request;
+ (id<AkaInterceptRequester>)startLoadingRequest:(nonnull NSURLRequest*)request withProtocolInstance:(nonnull AkaInterceptor*)protocolInstance;

- (void)stopLoading;

@end

/**
 * An AkaInterceptHandler listens for events from an
 * AkaInterceptRequester and may modify the request at key points.
 */
@protocol AkaInterceptHandler <NSObject>

+ (BOOL)canHandleRequest:(nonnull NSURLRequest*)request;
+ (id <AkaInterceptHandler>)instanceForRequest:(NSURLRequest*)request;

- (void)willRequest:(nonnull NSURLRequest*)request;
- (void)didReceiveResponse:(nonnull NSURLResponse*)response;
- (void)didReceiveData:(nonnull NSData*)data;
- (void)didFailWithError:(NSError *)error;
- (void)didCompleteWithError:(nullable NSError*)error;

@end

/**
 * Private class that keeps track of interception state.
 */
@interface AkaNetwork : NSObject

/**
 * Classes registered to make URL requests. These classes generate an instance
 * to perform the request.
 *
 * These are asked in sequence if they will handle the request. The first to
 * respond becomes the sole requester. The requester notifies AkaInterceptor
 * as the download progresses, which notifies all intercept handlers. Requesters
 * do not receive handler callbacks because they are the originators.
 */
@property (nonatomic, strong) NSMutableArray<Class<AkaInterceptRequester>> *interceptRequesterClasses;

/**
 * Classes registered as listeners for URL request progress. These classes
 * generate an instance to receive notifications.
 *
 * Intercept handlers are notified of URL request updates by the AkaInterceptor,
 * which, in turn, gets its progress from an intercept requester.
 */
@property (nonatomic, strong) NSMutableArray<Class<AkaInterceptHandler>> *interceptHandlerClasses;

/**
 * Get shared Common Network instance.
 */
+ (nonnull instancetype)shared;


@end

NS_ASSUME_NONNULL_END
