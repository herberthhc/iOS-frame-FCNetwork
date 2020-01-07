//
//  FCNetworkManager.h
//  FCNetwork
//
//  Created by LeoLiu on 2019/12/23.
//  Copyright (c) 2019 ForestCocoon ltyfantasy@163.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "FCNetworkDefines.h"

@class FCNetworkRequest, FCNetworkParser, AFHTTPSessionManager;
@protocol AFMultipartFormData, FCNetworkInterceptor;

#pragma mark - Defines

typedef NS_ENUM(NSUInteger, FCNetworkLogLevel) {
    
    FCNetworkLogLevelVerbose,
    FCNetworkLogLevelWarning,
    FCNetworkLogLevelError,
    FCNetworkLogLevelNone,
};

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Main Class

@interface FCNetworkManager : NSObject

- (instancetype)init __attribute__((unavailable("use + manager instead")));
+ (instancetype)new __attribute__((unavailable("use + manager instead")));

/**
    单例获取
 */
+ (instancetype)manager;

// --------------- 基础设置 ---------------

/**
    设置日志等级，仅在DEBUG模式下启用
    只有高于且等于level的日志才会被打印
    None > Error > Warning > Verbose
 */
- (void)setLogLevel:(FCNetworkLogLevel)level;

/**
    设置一个错误处理类，必须继承自FCNetworkError
 */
- (void)setErrorClass:(Class)errorClass;

/**
    设置拦截器，具体业务需要实现拦截协议
 */
- (void)setInterceptor:(id<FCNetworkInterceptor>)interceptor;

// --------------- Session管理 ---------------

/**
    添加AFHTTPSessionManager
 */
- (void)addSessionManager:(AFHTTPSessionManager*)sessionManager withIdentifier:(NSString*)identifier;

/**
    移除AFHTTPSessionManager
 */
- (void)removeSessionManagerWithIdentifier:(NSString*)identifier;

/**
    获取指定identifier的AFHTTPSessionManager
 */
- (AFHTTPSessionManager*)sessionManagerWithIdentifier:(NSString*)identifier;

// --------------- 请求 ---------------

/**
    发起普通网络请求
 
    @param request 请求体对象，包含URL、请求类型、参数
    @param parser 响应数据解析器，判断服务端返回数据是否正确，并解析数据成对象
    @param successBlock 请求成功回调
    @param failureBlock 请求失败回调
 
    @return task对象
 */
- (NSURLSessionTask*)sendRequest:(nonnull FCNetworkRequest*)request
                          parser:(FCNetworkParser*)parser
                    successBlock:(nonnull FCNetworkSuccessBlock)successBlock
                    failureBlock:(nonnull FCNetworkFailureBlock)failureBlock;

- (NSURLSessionTask*)sendUploadRequest:(nonnull FCNetworkRequest*)request
                                parser:(FCNetworkParser*)parser
                          successBlock:(nonnull FCNetworkSuccessBlock)successBlock
                         progressBlock:(FCNetworkProgressBlock)progressBlock
             constructingBodyWithBlock:(nonnull void (^)(id <AFMultipartFormData> formData))constructingBodyBlock
                          failureBlock:(nonnull FCNetworkFailureBlock)failureBlock;

- (NSURLSessionTask*)sendDownloadRequest:(nonnull FCNetworkRequest*)request
                                  parser:(FCNetworkParser*)parser
                            successBlock:(nonnull FCNetworkDownloadSuccessBlock)successBlock
                           progressBlock:(FCNetworkProgressBlock)progressBlock
                        destinationBlock:(nonnull NSURL * (^)(NSURL *targetPath, NSURLResponse *response))destinationBlock
                            failureBlock:(nonnull FCNetworkFailureBlock)failureBlock;

@end

NS_ASSUME_NONNULL_END
