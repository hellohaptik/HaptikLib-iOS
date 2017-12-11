//
//  HPSignUpObject.h
//  HaptikLib
//
//  Created by SimranJot Singh on 29/09/17.
//  Copyright © 2017 Haptik. All rights reserved.
//



#import "Haptik.h"

@class HPSignUpBuilder;

NS_ASSUME_NONNULL_BEGIN

@interface HPSignUpObject : NSObject

/*
 *  One of the three different authentication types would be need to use in order to sign up the user.
 *  In all three authentication types, name is a mandatory field.
 *  For HaptikLibAuthTypeTOI_SSO of authentication, verified phone number, authToken (SSO ticketId) as well as city is already required.
 *  For HaptikLibAuthTypeOTP of authentication, apart from everything above, even email is mandatory.
 */

@property (assign, readonly) HaptikLibAuthType authType;

/*
 *  The name of the user for signUp. Required in all HaptikLibAuthTypes.
 */

@property (nonatomic, readonly) NSString *userFullName;

/*
 *  The email of the user for signUp. Required in HaptikLibAuthTypeOTP.
 */

@property (nonatomic, readonly) NSString *userEmail;

/*
 *  The phone number of the user for signUp. Required in HaptikLibAuthTypeOTP and HaptikLibAuthTypeTOI_SSO.
 */

@property (nonatomic, readonly) NSString *userPhoneNumber;

/*
 *  The city of the user for signUp. Required in HaptikLibAuthTypeOTP and HaptikLibAuthTypeTOI_SSO.
 */

@property (nonatomic, readonly) NSString *userCity;

/*
 *  The authentication token for signUp. Required in HaptikLibAuthTypeOTP and HaptikLibAuthTypeTOI_SSO.
 */

@property (nonatomic, readonly) NSString *authToken;

/*
 *  If true then user's smartwallet would be created, and system wide wallet functionality would be possible to use. Note that if this is true then other information such as phone, email and city are also passed.
 */

@property (assign, readonly) BOOL shouldUseSmartWallet;

/*
 *  If true then user will be able to make use of Referral's.
 */

@property (assign, readonly) BOOL shouldUseReferralSystem;

/*
 *  A class method which builds the "HPSignUpBuilder" object and initalizes your "HPSignUpObject" object with the data provided.
 *  @param authType :The HaptikLibAuthType you wish to signup your user
 *  @param builderData : The builder data provided in the block.
 */

+ (instancetype)buildWith:(HaptikLibAuthType)authType data:(void (^)(HPSignUpBuilder * builder))builderData;


NS_ASSUME_NONNULL_END

@end



NS_ASSUME_NONNULL_BEGIN

@interface HPSignUpBuilder : NSObject

@property (nonatomic) NSString *userFullName;

@property (nonatomic) NSString *userEmail;

@property (nonatomic) NSString *userPhoneNumber;

@property (nonatomic) NSString *userCity;

@property (assign) BOOL shouldUseSmartWallet;

@property (assign) BOOL shouldUseReferralSystem;

@property (nonatomic) NSString *authToken;

/*
 *  This method is used internally. DO NOT USE THIS METHOD.
 */
- (HPSignUpObject *)buildWithAuthType:(HaptikLibAuthType)authType;

NS_ASSUME_NONNULL_END

@end




