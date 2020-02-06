//
//  HPSignUpObject.h
//  HaptikLib - Haptik Personal Assistant SDK for iOS
//
//  Copyright © 2018 Haptik. All rights reserved.
//
//  Usage of this SDK is subject to the Haptik Terms of
//  Service: https://haptik.ai/terms-conditions
//


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
     builder.authToken = @"";
     builder.authID = @"";
     builder.viaName = @"mychannelinhaptik";
 }];
 
 [[Haptik sharedSDK] signUpWith:signupObj
                     completion:^(BOOL success, __kindof UIViewController * _Nullable viewController, NSError * _Nullable error) {
 
     if (success) {
 
        //If via name is provided then after signup the SDK will give back an instance of UIViewController that you can directly push the user too.
        [self.navigationController pushViewController:viewController animated:YES];
     }
     else {
 
         UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Oops!"
                                                                        message:error.localizedDescription
                                                                 preferredStyle:UIAlertControllerStyleAlert];
 
         UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK"
                                                          style:UIAlertActionStyleCancel
                                                        handler:nil];
         [alert addAction:action];
         [self presentViewController:alert animated:YES completion:nil];
     }
 }];
 
 @endcode
 */
+ (instancetype)buildWithAuthType:(NSString *)authType data:(void (^)(HPSignUpBuilder * builder))builderData;


- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Signup Configuration Attributes

/// Different authentication types are there in order to sign up the user. Contact Haptik to get your authType.
@property (nonatomic, readonly) NSString *authType;

/// The name of the user for signUp.
@property (nullable, nonatomic, readonly) NSString *userFullName;

/// The email of the user for signUp.
@property (nullable, nonatomic, readonly) NSString *userEmail;

/// The phone number of the user for signUp.
@property (nullable, nonatomic, readonly) NSString *userPhoneNumber;

/// The authentication token for signUp.
@property (nullable, nonatomic, readonly) NSString *authToken;

/// The authentication ID for signUp. Required in all types except Basic Auth Type.
@property (nullable, nonatomic, readonly) NSString *authID;

/// Optional attribute if provided then after signup the SDK will give back an instance of UIViewController that you can directly push the user too.
@property (nullable, nonatomic, readonly) NSString *viaName;

/// Optional attribute if provided, this data will be logged in the backend and will be used in the chat flows acording to the business contract.
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NSString *> *customData;

/// Optioanal attribute if provided the chat will be initiated with this custom launch message
@property (nullable, nonatomic, readonly) NSString *launchMessage;

/// If YES then the launch message passed will not be visible to the user in the chat.
/// Message will be sent to the backend in both the cases.
/// Defaults to NO
@property (assign) BOOL hideLaunchMessage;

@end


/*--------------------------------------------*/

#pragma mark - Signup Builder

@interface HPSignUpBuilder : NSObject

@property (nonatomic) NSString *userFullName;

@property (nonatomic) NSString *userEmail;

@property (nonatomic) NSString *userPhoneNumber;

@property (nonatomic) NSString *authToken;

@property (nonatomic) NSString *authID;

@property (nonatomic) NSString *viaName;

@property (nonatomic) NSDictionary<NSString *, NSString *> *customData;

@property (nonatomic) NSString *launchMessage;

@property (assign) BOOL hideLaunchMessage;

- (HPSignUpObject *)buildWithAuthType:(NSString *)authType;

@end

NS_ASSUME_NONNULL_END

