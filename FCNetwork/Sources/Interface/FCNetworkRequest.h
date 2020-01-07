//
//  FCNetworkRequest.h
//  FCNetwork
//
//  Created by 刘天羽 on 2019/12/23.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>
#import "FCNetworkDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface FCNetworkRequest : NSObject

/// 该请求所对应的AFHTTPSessionManager对象
@property (nonatomic, copy) NSString *sessionIdentifier;
/// 请求URL地址
@property (nonatomic, copy) NSString *url;
/// 请求方式
@property (nonatomic, assign) FCNetworkRequestMode requestMode;
/// 超时时间
@property (nonatomic, assign) NSInteger timeoutInterval;

/**
    请求头参数，需要子类继承并实现
 */
- (NSDictionary*)headerParams;

/**
    请求体参数，需要子类继承并实现
 */
- (NSDictionary*)bodyParams;




// -------------- 缓存相关 --------------

/// 是否启用请求缓存机制
@property (nonatomic, assign) BOOL enableCache;
/// 缓存类型
@property (nonatomic, assign) FCNetworkCacheType cacheType;
/// 缓存有效期，默认-1，值 <= 0为无时限，> 0 时为设置的时间，单位 ( 秒 )
@property (nonatomic, assign) NSInteger cacheExpireTime;

/**
    计算请求的缓存key值
 
    key = md5(requestMode + url + headerParams + bodyParams)
 */
- (NSString*)cacheKey;

@end

NS_ASSUME_NONNULL_END
