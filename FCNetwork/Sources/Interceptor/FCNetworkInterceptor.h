//
//  FCNetworkInterceptor.h
//  FCNetwork
//
//  Created by LeoLiu on 2019/12/23.
//  Copyright (c) 2019 ForestCocoon ltyfantasy@163.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "FCNetworkDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class FCNetworkRequest, FCNetworkParser, FCNetworkError;
@protocol FCNetworkInterceptor <NSObject>

@required
/**
    请求拦截
 
    拦截即将发起的请求
    注意，如果拦截返回YES，originalHandler successBlock failureBlock，必须要调用其中任意一个，让网络请求流程继续走下去
 
    需要子类自行重写实现内容
 
    @param request 即将发起的请求体对象
    @param originalHandler 原请求执行逻辑
    @param successBlock 请求成功回调
    @param failureBlock 请求失败回调
 
    @return YES 事件被拦截 NO 不拦截
 */
- (BOOL)interceptRequest:(FCNetworkRequest*)request
         originalHandler:(void(^)(void))originalHandler
            successBlock:(FCNetworkSuccessBlock)successBlock
            failureBlock:(FCNetworkFailureBlock)failureBlock;

/**
    错误拦截
 
    拦截发起请求的相关数据，以及回调块
    注意，如果拦截返回YES，一定要调用successBlock或者failureBlock，让网络请求流程继续走下去
 
    需要子类自行重写实现内容
 
    @param error parser解析出来的服务器错误
    @param request 请求体
    @param parser 对应请求的解析器
    @param successBlock 请求成功回调
    @param failureBlock 请求失败回调
 
    @return YES 事件被拦截 NO 不拦截
 */
- (BOOL)interceptError:(FCNetworkError*)error request:(FCNetworkRequest*)request parser:(FCNetworkParser*)parser successBlock:(FCNetworkSuccessBlock)successBlock failureBlock:(FCNetworkFailureBlock)failureBlock;

@end

NS_ASSUME_NONNULL_END
