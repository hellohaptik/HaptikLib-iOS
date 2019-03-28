//
//  HPReachabilityNotifier.h
//  Haptik
//
//  Created by SimranJot Singh on 08/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import "HPSharedConstants.h"

NS_ASSUME_NONNULL_BEGIN

#define InternetReachability [HPReachabilityNotifier sharedInstance]

@interface HPReachabilityNotifier : NSObject

@property (nonatomic) BOOL isReachable;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
