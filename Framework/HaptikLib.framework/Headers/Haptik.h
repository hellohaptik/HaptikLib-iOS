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
@class HPThemeService;

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


/*
 *  Everytime wallet balance is updated a notification is fired by HaptikLib for observing wallet balance updates.
 *  Updated balance can be fetched from "getHaptikWalletBalance()" method of Haptik class.
 */

static NSString *const HPWalletBalanceUpdated   = @"haptikWalletBalanceUpdated";


@protocol HPAnalyticsServiceDelegate <NSObject>
@optional

- (void)eventTracked:(NSString *)eventName forParams:(nullable NSDictionary *)params;

- (void)errorTracked:(NSString *)errorMessage forError:(nullable NSError *)error;

@end


@protocol HPShareAndEarnDelegate <NSObject>
@optional

- (void)shareAndEarnTapped;

@end

@interface Haptik : NSObject

/*
 * Shared Instance of Haptik. You can use the Macro for [Haptik shared] which is HaptikLib
 */
+ (instancetype)shared;


/*!
 Initialize the Haptik session with the app launch options.

 @param application Your singleton app object.
 @param launchOptions The launch options provided by the AppDelegate's `didFinishLaunchingWithOptions:` method.
 */
- (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;


/*!
 Specifies whether Haptik Lib will handle URL redirects
 @param url The url expected to be handled
 @param options A dictionary of URL handling options
 */
- (BOOL)isRedirectHandled:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;


/*
 *  @method
 *
 *  Returns a Bool indicating if the user is already signed up or not.
 */
- (BOOL)isUserSignedUp;


/*
 *  @method
 *
 *  Returns the Initial View Controller if the User has already signed up.
 */
- (__kindof UIViewController * _Nullable)getInitialVC;


/*
 @method
 
 SignIn the User with SignUp Data.
 
 @param signUpData :Object of HPSignUpObject
 @param completion :Completion Handler which will have the success or error information.
 */
- (void)signUpWith:(HPSignUpObject *)signUpData
        completion:(void (^)(BOOL success,__kindof UIViewController * _Nullable initialVC, NSError * _Nullable error))completion;


/*!
 @method
 
 @abstract
 Register the device to receive push notifications.
 
 @discussion
 This will associate the device token with the current user to allow push notifications to the user.
 
 @param deviceToken     device token as returned from application:didRegisterForRemoteNotificationsWithDeviceToken:
 */
- (void)setDeviceToken:(NSData *)deviceToken;


/*!
 @method
 
 @abstract
 Process a push notification based on its payload.
 
 @discussion
 By calling this method, Haptik will process upon the passed userInfo payload
 
 @param userInfo         notification payload
 */
- (void)handleNotificationWithUserInfo:(NSDictionary *)userInfo;


/*
 *  @method
 *
 *  By calling this method you will get an instance of Haptik Wallet Screen. This method should only be called after the user has signed up.
 *
 *  @param defaultsHistory  Boolean Value indicating whether the wallet history tab should be selected by default or not.
 *  @param delegate  If shouldUseReferrals property of Haptik is set to true, then the delegate will pass the callbacks when the Share and Earn View is Tapped in the Wallet Scene.
 *
 */
- (__kindof UIViewController *)getHaptikWalletViewController:(BOOL)defaultsToHistory shareAndEarnDelegate:(nullable id <HPShareAndEarnDelegate>)delegate;


/*
 *  @method
 *
 *  By calling this method you will get an instance of Transaction History Screen. This method should only be called after the user has signed up.
 *
 */
- (__kindof UIViewController *)getTransactionHistoryViewController;


/*
 *  Set HPThemeService Object.
 *
 *  @param theme :HPThemeService Object for applying Theming Configurations
 */
@property (nonatomic) HPThemeService *themeConfig;


/*
 *  Set Show Banners BOOL
 *
 *  This BOOL controls the visibility of Banners on the Inbox Screen of Haptik. By default the value will be true.
 */
@property (assign) BOOL showBanners;


/*
 *  Set Use Referrals BOOL
 *
 *  This BOOL controls the use of Referral Flows in Haptik. By default the value will be false.
 */
@property (assign) BOOL shouldUseReferrals;


/*
 *  Analytics Callback Object
 *
 *  If provided, Analytics Service Class will send delegate callbacks to the provided delegate self.
 */
@property (nonatomic, weak) id <HPAnalyticsServiceDelegate> analyticsCallbackObject;


/*
 *  @method
 *
 *  Returns boolean value indicating if User's Haptik Wallet has been created or not.
 */
- (BOOL)isHaptikWalletCreated;


/*
 *  @method
 *
 *  Returns String value of User's Haptik Wallet Balance. Will return nil if:
 *
 *  - User's wallet has not been created yet.
 *  - Haptik Wallet Servers are currently down.
 */
- (NSString *)getHaptikWalletBalance;


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
