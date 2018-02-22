//
//  HPSignUpObject.h
//  HaptikLib - Haptik Personal Assistant SDK for iOS
//
//  Copyright © 2018 Haptik. All rights reserved.
//
//  Usage of this SDK is subject to the Haptik Terms of
//  Service: https://haptik.ai/terms-conditions
//


#import "Haptik.h"

@class HPSignUpBuilder;


NS_ASSUME_NONNULL_BEGIN

@interface HPSignUpObject : NSObject

#pragma mark - Signup Initializer

/*!
 @method
 A class method which builds the "HPSignUpBuilder" object and initalizes your "HPSignUpObject" object with the data provided.
 
 @param authType :The HaptikLibAuthType you wish to signup your user
 @param builderData : The builder data provided in the block.
 */
+ (instancetype)buildWith:(HaptikLibAuthType)authType data:(void (^)(HPSignUpBuilder * builder))builderData;


- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Signup Configuration Attributes

/*!
    Three different authentication types are there in order to sign up the user.
    For HaptikLibAuthTypeSSO & HaptikLibAuthTypeOTP types of authentication, verified phone number and authToken are the required fields.
 */
@property (nonatomic, readonly) HaptikLibAuthType authType;


/*!
    The name of the user for signUp.
    Required in all HaptikLibAuthTypes.
 */
@property (nullable, nonatomic, readonly) NSString *userFullName;


/*!
    The email of the user for signUp.
    Required in HaptikLibAuthTypeOTP.
 */
@property (nullable, nonatomic, readonly) NSString *userEmail;


/*!
    The phone number of the user for signUp.
    Required in HaptikLibAuthTypeOTP and HaptikLibAuthTypeSSO.
 */
@property (nullable, nonatomic, readonly) NSString *userPhoneNumber;


/*!
    The city of the user for signUp.
    Required in HaptikLibAuthTypeOTP and HaptikLibAuthTypeSSO.
 */
@property (nullable, nonatomic, readonly) NSString *userCity;


/*!
    The authentication token for signUp.
    Required in HaptikLibAuthTypeOTP and HaptikLibAuthTypeSSO.
 */
@property (nullable, nonatomic, readonly) NSString *authToken;


/*!
    If true then user's smartwallet would be created, and system wide wallet functionality would be possible to use.
    Note that if this is true then other information such as phone, email and city are also passed.
 */
@property (nonatomic, readonly) BOOL shouldUseSmartWallet;


/*!
    If true then user will be able to make use of Referral's.
 */
@property (nonatomic, readonly) BOOL shouldUseReferralSystem;


@end


/*--------------------------------------------*/


#pragma mark - Signup Builder

@interface HPSignUpBuilder : NSObject

@property (nonatomic) NSString *userFullName;

@property (nonatomic) NSString *userEmail;

@property (nonatomic) NSString *userPhoneNumber;

@property (nonatomic) NSString *userCity;

@property (nonatomic) BOOL shouldUseSmartWallet;

@property (nonatomic) BOOL shouldUseReferralSystem;

@property (nonatomic) NSString *authToken;


- (HPSignUpObject *)buildWithAuthType:(HaptikLibAuthType)authType;

@end

NS_ASSUME_NONNULL_END

