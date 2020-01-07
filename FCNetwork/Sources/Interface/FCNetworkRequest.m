//
//  FCNetworkRequest.m
//  FCNetwork
//
//  Created by LeoLiu on 2019/12/23.
//  Copyright (c) 2019 ForestCocoon ltyfantasy@163.com. All rights reserved.

#import "FCNetworkRequest.h"
#import <CommonCrypto/CommonDigest.h>

@interface FCNetworkRequest ()

@end

@implementation FCNetworkRequest

#pragma mark - Init

- (instancetype)init {
    
    if (self = [super init]) {
        
        _url = @"";
        _requestMode = FCNetworkRequestModeGET;
        _timeoutInterval = 30;
        
        _enableCache = NO;
        _cacheExpireTime = -1;
    }
    return self;
}

#pragma mark - Params

- (void)setTimeoutInterval:(NSInteger)timeoutInterval {
    _timeoutInterval = timeoutInterval <= 0 ? 5 : timeoutInterval;
}

- (NSDictionary *)headerParams {
    return @{};
}

- (NSDictionary *)bodyParams {
    return @{};
}

#pragma mark - Cache Data

- (NSString *)cacheKey {
    
    NSString *headerParamsValue = @"";
    NSDictionary *headerParams = [self headerParams];
    if (headerParams.count > 0) {
        headerParamsValue = [self JSONStringWithDictionary:headerParams];
    }
    
    NSString *bodyParamsValue = @"";
    NSDictionary *bodyParams = [self bodyParams];
    if (bodyParams.count > 0) {
        bodyParamsValue = [self JSONStringWithDictionary:bodyParams];
    }
    
    NSString *cacheString = [NSString stringWithFormat:@"%@_%tu_%@_%@", _url, _requestMode, headerParamsValue, bodyParamsValue];
    return [self md5WithString:cacheString];
}

#pragma mark - Convert

- (NSString *)JSONStringWithDictionary:(NSDictionary *)dictionary {
    
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dictionary options:kNilOptions error:nil];
    NSString *jsonStr = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    
    return jsonStr;
}

- (NSString *)md5WithString:(NSString*)string {
    
    // 利用NSData来计算，是因为直接用NSString来计算并不安全，可能要处理\0字符，还有中文等原因
    // 大多数情况下，用NSString直接计算没有问题，只有极个别情况下，会有问题
    NSData *data = [string dataUsingEncoding:NSUTF8StringEncoding];
    const char *str = [data bytes];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(str, (CC_LONG)data.length, result);
    
    NSMutableString *code = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for (int i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        [code appendFormat:@"%02x", result[i]];
    }
    
    return code;
}

#pragma mark - Print

- (NSString *)description {
    return [NSString stringWithFormat:@"[FCNetworkRequest] %@\n"
                                       "\tURL - %@\n"
                                       "\tHeader - %@\n"
                                       "\tBody - %@",
                                        NSStringFromClass(self.class),
                                        _url,
                                        self.headerParams,
                                        self.bodyParams];
}

@end
