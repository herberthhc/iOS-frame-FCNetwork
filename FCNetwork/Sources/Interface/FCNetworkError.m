//
//  FCNetworkError.m
//  FCNetwork
//
//  Created by LeoLiu on 2019/12/23.
//  Copyright (c) 2019 ForestCocoon ltyfantasy@163.com. All rights reserved.

#import "FCNetworkError.h"

@implementation FCNetworkError

+ (instancetype)errorWithSystemError:(NSError *)error {
    return [FCNetworkError errorWithErrorCode:error.code errorDescription:error.localizedDescription];
}

+ (instancetype)errorWithErrorCode:(NSInteger)errorCode errorDescription:(NSString *)errorDescription {
    
    FCNetworkError *error = [FCNetworkError new];
    error.errorCode = errorCode;
    error.errorDescription = errorDescription;
    return error;
}

@end
