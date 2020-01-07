//
//  FCNetworkParser.h
//  FCNetwork
//
//  Created by 刘天羽 on 2019/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FCNetworkError;
@interface FCNetworkParser : NSObject

@property (nonatomic, strong) id originResponseData;

/**
 该方法用于解析返回数据，并判断是否存在业务层的错误
 如：
    1，服务端返回数据格式有误
    2，服务端返回了业务层错误码
 */
- (FCNetworkError *)verifyResponse:(id)responseObject;

/**
 该方法用于解析服务端返回的业务信息，并生成业务对象
 */
- (id)parseResponse:(id)responseObject;

@end

NS_ASSUME_NONNULL_END
