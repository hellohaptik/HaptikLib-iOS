//
//  HaptikUser.h
//  HaptikBase
//
//  Created by SimranJot Singh on 11/01/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HaptikWallet;

NS_ASSUME_NONNULL_BEGIN

@interface HaptikUser : NSObject < NSSecureCoding >

@property (nonatomic, assign) BOOL active;
@property (nonatomic, assign) BOOL waiting;
@property (nonatomic, assign) BOOL otp_verified;

@property (nonatomic, assign) BOOL referral_used;
@property (nonatomic, assign) BOOL referral_redeemed;
@property (nonatomic, assign) BOOL push_notification;

@property (nullable, nonatomic) NSString *dob;
@property (nullable, nonatomic) NSString *name;
@property (nullable, nonatomic) NSString *email;
@property (nullable, nonatomic) NSString *gender;
@property (nullable, nonatomic) NSString *fullName;
@property (nullable, nonatomic) NSDate *created_at;

@property (nonatomic) NSUInteger unread;
@property (nonatomic) NSUInteger protocol_version;
@property (nonatomic) NSUInteger bannersPerCarousel;

@property (nullable, nonatomic) NSString *mqtt_url;
@property (nullable, nonatomic) NSString *auth_code;
@property (nullable, nonatomic) NSString *user_name;
@property (nullable, nonatomic) NSString *os_version;
@property (nullable, nonatomic) NSString *app_version;
@property (nullable, nonatomic) NSString *device_token;
@property (nullable, nonatomic) NSString *build_version;

@property (nullable, nonatomic) NSString *guest_user_id;
@property (nullable, nonatomic) NSString *userIdentifier;

@property (nullable, nonatomic) NSString *city;
@property (nullable, nonatomic) NSString *timezone;
@property (nullable, nonatomic) NSString *mobile_no;
@property (nullable, nonatomic) NSString *airportCode;
@property (nullable, nonatomic) NSString *mobileOperator;

@property (nullable, nonatomic) NSString *password;
@property (nullable, nonatomic) NSString *phone_model;
@property (nullable, nonatomic) NSString *package_name;

@property (nullable, nonatomic) NSString *location;
@property (nullable, nonatomic) NSString *location_address;
@property (nullable, nonatomic) NSString *location_updated_at;
@property (nullable, nonatomic) NSString *location_address_updated_at;

@property (nullable, nonatomic) HaptikWallet *wallet;

@end

NS_ASSUME_NONNULL_END
