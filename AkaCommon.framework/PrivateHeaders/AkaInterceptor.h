//
//  AkaInterceptor.h
//  AkaCommon
//
//  Created by Brian Salomon on 4/24/19.
//  Copyright © 2019 Akamai Technologies, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AkaNetwork.h"

NS_ASSUME_NONNULL_BEGIN

@interface AkaInterceptor : NSURLProtocol

- (void)wasRedirectedToRequest:(NSMutableURLRequest *)request redirectResponse:(NSURLResponse *)response;
- (void)didReceiveResponse:(nullable NSURLResponse *)response cacheStoragePolicy:(NSURLCacheStoragePolicy)policy;
- (void)didReceiveData:(nullable NSData *)data;
- (void)didFailWithError:(NSError *)error;
- (void)didFailForHandlerOnlyWithError:(NSError *)error;
- (void)didCompleteWithError:(nullable NSError *)error;

// Get custom property from the request.
- (id)propertyForKey:(NSString*)key inRequest:(NSMutableURLRequest*)request;

// Set custom property on the request.
- (void)setProperty:(id)value forKey:(NSString*)key inRequest:(NSMutableURLRequest*)request;

@end

NS_ASSUME_NONNULL_END
