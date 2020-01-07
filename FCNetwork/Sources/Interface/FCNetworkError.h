//
//  FCNetworkError.h
//  FCNetwork
//
//  Created by 刘天羽 on 2019/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FCNetworkError : NSObject

/**
    错误码
 */
@property (nonatomic, assign) NSInteger errorCode;
/**
    错误描述
 */
@property (nonatomic, copy) NSString *errorDescription;
/**
    原始错误对象，如果有的话
 */
@property (nullable, nonatomic, strong) NSError *originError;

/**
    转换底层错误为业务层错误
    建议子类重写，转换为自己业务层下的错误枚举
 */
+ (instancetype)errorWithSystemError:(NSError*)error;

/**
    构建便捷方法
 */
+ (instancetype)errorWithErrorCode:(NSInteger)errorCode errorDescription:(NSString*)errorDescription;

@end

NS_ASSUME_NONNULL_END
