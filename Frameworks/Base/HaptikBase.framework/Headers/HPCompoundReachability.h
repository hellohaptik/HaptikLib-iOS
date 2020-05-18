//
//  HPCompoundReachability.h
//  HaptikBase
//
//  Created by SimranJot Singh on 27/04/20.
//  Copyright © 2020 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "HPNetworkReachabilityManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HPCompoundReachabilityStatus) {
    HPCompoundReachabilityStatusUnknown = -1,
    HPCompoundReachabilityStatusNotReachable = 0,
    HPCompoundReachabilityStatusViaWWAN = 1,
    HPCompoundReachabilityStatusViaWiFi = 2
};

/**
 * The class combines the default reachabilty and ping tests to correctly determine the actual reachablity of the device.
 */

@interface HPCompoundReachability : NSObject

@property (nonatomic, strong) HPNetworkReachabilityManager *localReachability;

@property (nonatomic, copy) NSString *pingHost;

@property (nonatomic, copy) NSString *alternativePingHost;

@property (nonatomic, assign) float autoPingInterval;

/// Timeout used for ping. Default is 2 seconds
@property (nonatomic, assign) NSTimeInterval pingTimeout;

/// Latency from latest ping result
@property (nonatomic, assign) NSTimeInterval latency;

+ (instancetype)shared;

- (void)startMonitoring;

- (void)stopMonitoring;

- (BOOL)isReachable;

/// Return current reachability immediately.
- (HPCompoundReachabilityStatus)currentReachabilityStatus;

/// Returns previous reachability status.
- (HPCompoundReachabilityStatus)previousReachabilityStatus;

@end

NS_ASSUME_NONNULL_END
