//
//  HPAnalyticsService.h
//  HaptikLib
//
//  Created by SimranJot Singh on 02/11/17.
//  Copyright © 2017 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN


#pragma mark - Analytics Service

/**
 @protocol  HPAnalyticsServiceDelegate
 
 @discussion
 HPAnalyticsServiceDelegate gives out an optional method which if you confirm to will give callbacks of all the events that the HaptikSDK fires.
 */
@protocol HPAnalyticsServiceDelegate <NSObject>

@optional
- (void)eventTracked:(NSString *)eventName forParams:(nullable NSDictionary *)params;

@end

/**
 @class HPAnalyticsService
 
 @discussion
 HaptikSDK uses CleverTap for analytics across all the modules. This class provides a neat interface for a couple of things:
 
 - Get Delegate Callbacks for all the events that HaptikSDK fires
 - Track any sort of event that you want to for your purpose for the user
 - Push user attributes to his CleverTap Profile
 
 */
@interface HPAnalyticsService : NSObject < HPAnalyticsServiceDelegate >

/**
 @abstract
 Records an event with parameters.
 
 @discussion
 Parameters keys must be NSString and values must be one of NSString, NSNumber, BOOL or NSDate.
 Keys are limited to 32 characters.
 Values are limited to 40 bytes.
 Longer will be truncated.
 Maximum number of event properties is 16.
 
 @param eventName   event name
 @param params      parameters dictionary
 */
+ (void)trackEvent:(NSString *)eventName withParams:(NSMutableDictionary * _Nullable)params;


@end

NS_ASSUME_NONNULL_END
