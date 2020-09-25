//
//  HPNetworkingClient.h
//  HaptikBase
//
//  Created by SimranJot Singh on 16/04/20.
//  Copyright © 2020 Haptik. All rights reserved.
//

#import <HaptikBase/HPHTTPSessionManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface HPNetworkingClient : HPHTTPSessionManager

+ (instancetype)sharedClient;

@end

NS_ASSUME_NONNULL_END
