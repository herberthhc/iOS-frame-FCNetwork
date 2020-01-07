//
//  FCNetworkError.m
//  FCNetwork
//
//  Created by 刘天羽 on 2019/12/23.
//

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
