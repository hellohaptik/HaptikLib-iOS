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
 
 @param authType :The Auth_Type you wish to signup your user. Contact Haptik for getting the value of this parameter and use the EXACT value.
 @param builderData : The builder data provided in the block.
 
 @code
 
 HPSignUpObject *signupObj = [HPSignUpObject buildWithAuthType:@"AUTH_TYPE_HERE" data:^(HPSignUpBuilder * _Nonnull builder) {
 
     builder.userFullName = @"John Appleseed";
     builder.userPhoneNumber = @"9870000000";
     builder.userEmail = @"john@apple.com";
     builder.userCity = @"Mumbai";
     builder.authToken = @"";
     builder.authID = @"";
 }];
 
 UIViewController *initialVC = [[Haptik sharedSDK] signUpWithLoadingScreenFor:signupObj completion:^(BOOL success, NSError * _Nullable error) {
 
     if (success) {
         // do housekeeping
     }
     else {
         UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Oops!"
         message:error.localizedDescription
         preferredStyle:UIAlertControllerStyleAlert];
 
         UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:nil];
         [alert addAction:action];
         [self presentViewController:alert animated:YES completion:nil];
     }
 }];
 
 [self.navigationController pushViewController:initialVC animated:YES];
 
 @endcode
 */
+ (instancetype)buildWithAuthType:(NSString *)authType data:(void (^)(HPSignUpBuilder * builder))builderData;


- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Signup Configuration Attributes

/*!
    Different authentication types are there in order to sign up the user.
    For (Auth_Type = (TOI_SSO | OTP)) types of authentication, verified phone number and authToken are the required fields.
 */
@property (nonatomic, readonly) NSString *authType;


/*!
    The name of the user for signUp.
    Required in all types except Basic Auth Type.
 */
@property (nullable, nonatomic, readonly) NSString *userFullName;


/*!
    The email of the user for signUp.
    Required in OTP Auth Type.
 */
@property (nullable, nonatomic, readonly) NSString *userEmail;


/*!
    The phone number of the user for signUp.
    Required in all types except Basic Auth Type.
 */
@property (nullable, nonatomic, readonly) NSString *userPhoneNumber;


/*!
    The city of the user for signUp.
    Required in OTP Auth Type.
 */
@property (nullable, nonatomic, readonly) NSString *userCity;


/*!
    The authentication token for signUp.
    Required in all types except Basic Auth Type.
 */
@property (nullable, nonatomic, readonly) NSString *authToken;


/*!
 The authentication ID for signUp.
 Required in all types except Basic Auth Type.
 */
@property (nullable, nonatomic, readonly) NSString *authID;


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

@property (nonatomic) NSString *authID;


- (HPSignUpObject *)buildWithAuthType:(NSString *)authType;

@end

NS_ASSUME_NONNULL_END

