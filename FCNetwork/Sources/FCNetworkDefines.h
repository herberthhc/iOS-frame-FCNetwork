//
//  FCNetworkDefines.h
//  Pods
//
//  Created by 刘天羽 on 2019/12/25.
//

#ifndef FCNetworkDefines_h
#define FCNetworkDefines_h

@class FCNetworkError;

// ---------- 请求类型 -----------
typedef NS_ENUM(NSUInteger, FCNetworkRequestMode) {
    
    FCNetworkRequestModeGET,
    FCNetworkRequestModeDELETE,
    FCNetworkRequestModePOST,
    FCNetworkRequestModePUT,
};

// ---------- 缓存类型 -----------
typedef NS_ENUM(NSUInteger, FCNetworkCacheType) {
    FCNetworkCacheTypeRAM,
    FCNetworkCacheTypeTemp,
    FCNetworkCacheTypeCache,
};

// ---------- 回调Block -----------
typedef void (^FCNetworkSuccessBlock) (id response);
typedef void (^FCNetworkDownloadSuccessBlock) (NSURL *filePath);
typedef void (^FCNetworkFailureBlock) (FCNetworkError *error);
typedef void (^FCNetworkProgressBlock) (NSProgress *progress);
typedef void (^FCNetworkCacheBlock) (id cache);

#endif /* FCNetworkDefines_h */
