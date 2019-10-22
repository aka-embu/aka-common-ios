//
//  AkaSharedURLSession.h
//  AkaCommon
//
//  Created by Brian Salomon on 7/23/19.
//  Copyright © 2019 Akamai Technologies, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 Objects that want to participate in shared URL session need to implement this protocol and all the required
 methods.
 */
@protocol AkaSharedURLSessionTaskHandler <NSObject, NSURLSessionDataDelegate, NSURLSessionDownloadDelegate>
@end




/*!
 This protocol allows several objects to share the same NSURLSession and have the implementing object
 dispatch task callbacks to the appropriate object responsible for handling the http task.
 */
@protocol AkaSharedURLSession <NSObject>

@property (readonly,nonnull,nonatomic) NSURLSession *session;

/*!
 Registers handler object that will handle task callbacks for the given http task.
 */
- (void)registerHandlerFor:(nonnull NSURLSessionTask*)httpTask
				   handler:(nonnull NSObject<AkaSharedURLSessionTaskHandler>*)taskHandler;

/*!
 Returns handler responsible for the http task. Performs all the necessary checks before returning result.
 If the http task cannot be matched to a task handler, or any other inconsistency returns nil.
 Does not modify http task.
 */
- (nullable NSObject<AkaSharedURLSessionTaskHandler>*)getHandlerFor:(nonnull NSURLSessionTask*)httpTask
															 dbgMsg:(nonnull NSString*)dbgMsg;

@end






/*!
 Dispatches task related url session delegate callbacks to handlers registered for the specific http task.
 Session related delegate callbacks are dispatched to baseUrlSessionDelegate if provided.
 */
@interface AkaSharedURLSession : NSObject <AkaSharedURLSession>

@property (readonly,nonnull,nonatomic) NSURLSession *session;

+ (nonnull instancetype)sharedUrlSession:(nonnull NSURLSessionConfiguration*)config
							baseDelegate:(nullable NSObject<NSURLSessionDataDelegate, NSURLSessionDownloadDelegate>*)baseDelegate
						   delegateQueue:(nullable NSOperationQueue *)queue;

/*!
 Registers handler object that will handle task callbacks for the given http task.
 */
- (void)registerHandlerFor:(nonnull NSURLSessionTask*)httpTask
				   handler:(nonnull NSObject<AkaSharedURLSessionTaskHandler>*)taskHandler;

/*!
 Returns handler responsible for the http task. Performs all the necessary checks before returning result.
 If the http task cannot be matched to a task handler, or any other inconsistency returns nil.
 Does not modify http task.
 */
- (nullable NSObject<AkaSharedURLSessionTaskHandler>*)getHandlerFor:(nonnull NSURLSessionTask*)httpTask
															 dbgMsg:(nonnull NSString*)dbgMsg;

@end

NS_ASSUME_NONNULL_END
