//
//  FCNetworkCache.h
//  FCNetwork
//
//  Created by LeoLiu on 2019/12/23.
//  Copyright (c) 2019 ForestCocoon ltyfantasy@163.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "FCNetworkDefines.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Sub Class

@interface FCNetworkCacheData : NSObject <NSCoding>

@property (nonatomic, copy) NSString *key;
@property (nonatomic, strong) id responseObject;
@property (nonatomic, strong) NSDate *expireTime;

/// 判断数据是否失效，即有效期是否已过
- (BOOL)isInvalid;

@end

#pragma mark - Main Class

@interface FCNetworkCache : NSObject

- (instancetype)init __attribute__((unavailable("use + defaultCache instead")));
+ (instancetype)new __attribute__((unavailable("use + defaultCache instead")));

+ (instancetype)defaultCache;

/**
    取缓存
 
    取缓存顺序：RAM >> Tmp >> Cache
 */
- (FCNetworkCacheData*)dataForKey:(NSString*)key;

/**
    取缓存，从指定的type中读取
 */
- (FCNetworkCacheData*)dataForKey:(NSString *)key type:(FCNetworkCacheType)type;

/**
    存缓存
 */
- (void)saveData:(FCNetworkCacheData*)data forKey:(NSString*)key type:(FCNetworkCacheType)type;

/**
    删除指定缓存
 */
- (void)deleteDataForKey:(NSString*)key;

/**
    清空指定类型缓存
 */
- (void)cleanDataWithType:(FCNetworkCacheType)cacheType;

/**
    清空所有缓存
 */
- (void)cleanAllData;

@end

NS_ASSUME_NONNULL_END
