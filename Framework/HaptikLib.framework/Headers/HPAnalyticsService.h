//
//  HPAnalyticsService.h
//  HaptikLib
//
//  Created by SimranJot Singh on 02/11/17.
//  Copyright © 2017 Haptik. All rights reserved.
//

#import "Haptik.h"

NS_ASSUME_NONNULL_BEGIN

@interface HPAnalyticsService : NSObject < HPAnalyticsServiceDelegate >

+ (void)trackEvent:(NSString *)eventName withParams:(NSMutableDictionary * _Nullable)params;

+ (void)trackError:(NSString *)errorMessage withError:(NSError * _Nullable)error;

+ (void)setAttribute:(id)value forKey:(NSString *)key;

+ (void)setAttributes:(NSArray<NSString *> *)values forKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
