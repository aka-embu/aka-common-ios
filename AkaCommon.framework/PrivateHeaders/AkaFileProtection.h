//
//  AkaFileProtection.h
//  AkaCommon
//
//  Copyright © 2021 Akamai Technologies, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AkaFileProtection : NSObject

/**
 * NSFileProtectionType to use for creating new files.
 */
@property (readonly, strong, nonatomic) NSFileProtectionType level;

- (NSDictionary *)attributes;
- (NSDataWritingOptions)dataWritingOption;

+ (nonnull instancetype)shared;

+ (BOOL)applyParentsProtectionLevelForPath:(NSString *)path
                                 recursive:(BOOL)recursive;

+ (BOOL)changeProtectionLevel:(NSFileProtectionType)level
                      forPath:(NSString *)path
                    recursive:(BOOL)recursive;

+ (BOOL)changeProtectionLevel:(NSFileProtectionType)level
                      forPath:(NSString *)path;

+ (BOOL)changeProtectionLevel:(NSFileProtectionType)level
                     forPaths:(NSArray<NSString *> *)paths;

@end

NS_ASSUME_NONNULL_END
