//
//  Haptik.h
//  HaptikLib
//
//  Created by SimranJot Singh on 18/09/17.
//  Copyright © 2017 Haptik. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HPInitObject;
@class HPSignUpObject;


NS_ASSUME_NONNULL_BEGIN

/**
 *  HaptikLib Environment Enum
 */
typedef NS_ENUM(NSUInteger, HaptikLibRunEnvironment) {
    /*
     *  HaptikLibEnvProduction
     */
    HaptikLibEnvProduction = 0,
    /*
     *  HaptikLibEnvStaging
     */
    HaptikLibEnvStaging,
    /*
     *  HaptikLibEnvDev
     */
    HaptikLibEnvDev
};


/**
 *  HaptikLib SignUp Authentication Enum
 */
typedef NS_ENUM(NSUInteger, HaptikLibAuthType) {
    /*
     *  HaptikLibAuthTypeBasic
     */
    HaptikLibAuthTypeBasic = 0,
    /*
     *  HaptikLibAuthTypeOTP
     */
    HaptikLibAuthTypeOTP,
    /*
     *  HaptikLibAuthTypeTOI_SSO
     */
    HaptikLibAuthTypeTOI_SSO
};


@protocol HPAnalyticsServiceDelegate <NSObject>
@optional

- (void)eventTracked:(NSString *)eventName forParams:(nullable NSDictionary *)params;

- (void)errorTracked:(NSString *)errorMessage forError:(nullable NSError *)error;

@end


@interface Haptik : NSObject

/*
 * Shared Instance of Haptik. You can use the Macro for [Haptik shared] which is HaptikLib
 */
+ (instancetype)shared;


/*
 *  SignIn the User with SignUp Data.
 *
 *  @param signUpData :Object of HPSignUpObject
 *  @param initialVC  :Instance of initial ViewController
 *  @param completion :Completion Handler which will have the success or error information.
 */
- (void)signUpWith:(HPSignUpObject *)signUpData
        completion:(void (^)(BOOL success,__kindof UIViewController * _Nullable initialVC, NSError * _Nullable error))completion;


/*
 *  Set Device Token for Push Notifications.
 *
 *  @param token :Device Token you get on Registering Push Notifications
 */
- (void)setDeviceToken:(NSString *)token;


/*
 *  Analytics Callback Object
 *
 *  If provided, Analytics Service Class will send delegate callbacks to the provided delegate self.
 */
@property (nonatomic, weak) id <HPAnalyticsServiceDelegate> analyticsCallbackObject;


/*
 *  Gets the API key for the current app. This should only be called after the SDK has been initialized, will return (null) otherwise.
 */
- (NSString *)getApiKey;


/*
 *  Gets the client id for the current app. This should only be called after the SDK has been initialized, will return (null) otherwise.
 */
- (NSString *)getClientID;


/*
 *  Gets the base endpoint to use. This should only be called after the SDK has been initialized, will return (null) otherwise.
 */
- (NSString *)getBaseUrl;


/*
 *  Gets the run environment of the SDK. This should only be called after the SDK has been initialized, will return 0(HaptikLibEnvProduction) otherwise.
 */
- (HaptikLibRunEnvironment)getRunEnvironment;

@end

NS_ASSUME_NONNULL_END
