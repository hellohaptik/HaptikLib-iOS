//
//  HPAnalyticsAPI.h
//  HaptikBase
//
//  Created by SimranJot Singh on 24/11/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#ifndef HPAnalyticsAPI_h
#define HPAnalyticsAPI_h

NS_ASSUME_NONNULL_BEGIN

@protocol HPAnalyticsAPI <NSObject>

@required

/**
 @abstract
 Set's up and initializes the Clevertap SDK
*/
- (void)setupAnalytics;

/**
 @abstract
 Enables the Profile/Events Read and Synchronization API
*/
- (void)enablePersonalization;

/**
 @abstract
 Enables tracking opt out for the currently active user.

 @param optOut   BOOL Whether tracking opt out should be enabled/disabled.
*/
- (void)optOutFromAnalytics:(BOOL)optOut;

/**
 @abstract
 Enables the reporting of device network-related information, including IP address.  This reporting is disabled by default.

 @param enable  BOOL Whether device network info reporting should be enabled/disabled.
*/
- (void)enableDeviceNetworkInfoReporting:(BOOL)enable;

/**
 @abstract
 Convenience method to register the device push token as as string.
 This will associate the device token with the current user to allow push notifications to the user.

 @param pushToken   device token as returned from application:didRegisterForRemoteNotificationsWithDeviceToken: converted to an NSString.
*/
- (void)setPushTokenAsString:(NSString *)pushToken;

/**
 @abstract
 Determine whether a notification originated from the analytics service
 
 @param payload  notification payload
 */
- (BOOL)isHaptikAnalyticsNotification:(NSDictionary *)payload;

/**
 @abstract
 Track and process a push notification based on its payload.

 @param payload notification payload
*/
- (void)handleHaptikAnalyticsNotification:(NSDictionary *)payload;

/**
 @abstract
 Set attributes on the current user analyics profile.
 
 @discussion
 Attribute keys must be NSString and values must be one of NSString, NSNumber, BOOL, NSDate.
 
 @param attributes  attributes dictionary
 */
- (void)setAttributes:(NSDictionary *)attributes;

/**
 @abstract
 Queues an event to track with properties.

 @param eventName           event name
 @param params      properties dictionary
*/
- (void)queueEvent:(NSString *)eventName withParams:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END

#endif /* HPAnalyticsAPI_h */
