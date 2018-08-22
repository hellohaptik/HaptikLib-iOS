//
//  Haptik.h
//  HaptikLib - Haptik Personal Assistant SDK for iOS
//
//  Copyright © 2018 Haptik. All rights reserved.
//
//  Usage of this SDK is subject to the Haptik Terms of
//  Service: https://haptik.ai/terms-conditions
//


#import <UIKit/UIKit.h>

@class HPInitObject;
@class HPSignUpObject;
@class HPThemeService;


NS_ASSUME_NONNULL_BEGIN


#pragma mark - Run Environment

typedef NS_ENUM(NSUInteger, HaptikLibRunEnvironment) {
    
    HaptikLibEnvProduction = 0,
    HaptikLibEnvStage,
    HaptikLibEnvDevelopment
};


#pragma mark - Analytics Service

@protocol HPAnalyticsServiceDelegate <NSObject>
@optional
- (void)eventTracked:(NSString *)eventName forParams:(nullable NSDictionary *)params;
- (void)errorTracked:(NSString *)errorMessage forError:(nullable NSError *)error;
@end


#pragma mark - Share Haptik

@protocol HPShareAndEarnDelegate <NSObject>
@optional
- (void)shareAndEarnTapped;
@end


#pragma mark - Referral Code

@protocol ReferalCodeDelegate <NSObject>
@optional
- (void)onSuccess:(BOOL)success withDictionary:(NSDictionary *)dictionary;
@end


#pragma mark -

/*!
    Everytime wallet balance is updated a notification is fired by HaptikLib for observing wallet balance updates.
    Updated balance can also be fetched from `getHaptikWalletBalance()`
 */
UIKIT_EXTERN NSNotificationName const HPWalletBalanceUpdated;


/*!
    Everytime available offers count is updated a notification is fired by HaptikLib
    Updated available offers count can also be fetched from `getOffersCount()`
 */
UIKIT_EXTERN NSNotificationName const HPOffersUpdatedNotification;



@interface Haptik : NSObject

/*!
    Returns the Haptik singleton object
 */
+ (instancetype)sharedSDK;


- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Configuration Attributes

/*!
 Sets HPThemeService Object used for applying Theming Configurations
 
 @code
 
 [Haptik sharedSDK].themeConfig = [HPThemeService buildWithData:^(HPThemeServiceBuilder * _Nullable builder) {
 
     builder.brandColor = [UIColor colorWithRed:(33/250.0) green:(150/255.0) blue:(243/255.0) alpha:1];
     builder.businessChatBackground = [UIColor colorWithRed:(240/255.0) green:(240/255.0) blue:(240/255.0) alpha:1];
     builder.businessChatText = [UIColor colorWithRed:(51/255.0) green:(51/255.0) blue:(51/255.0) alpha:1];
     builder.messageTimeStamp = [UIColor colorWithRed:(119/255.0) green:(119/255.0) blue:(119/255.0) alpha:1];
     builder.lightFont = @"SFUIText-Light";
     builder.regularFont = @"SFUIText-Regular";
     builder.mediumFont =  @"SFUIText-Medium";
 }];
 
 @endcode
 */
@property (nonatomic) HPThemeService *themeConfig;


/*!
 Set Use Inbox BOOL
 This BOOL controls the visibility of Inbox Scene of Haptik. By default the value will be true.
 */
@property (nonatomic, assign) BOOL useInbox;


/*!
 Set Show Banners BOOL
 This BOOL controls the visibility of Banners on the Inbox Screen of Haptik. By default the value will be true.
 */
@property (nonatomic, assign) BOOL showBanners;


/*!
 Set Use Referrals BOOL
 This BOOL controls the use of Referral Flows in Haptik. By default the value will be false.
 */
@property (nonatomic, assign) BOOL shouldUseReferrals;


/*!
 Analytics Callback Object
 If provided, Analytics Service Class will send delegate callbacks to the provided delegate self.
 */
@property (nullable, nonatomic, weak) id <HPAnalyticsServiceDelegate> analyticsCallbackObject;


/*!
 Sets the Custom Title text to be shown on the Loading Screen. If not provided, default text will be shown.
 */
@property (nullable, nonatomic) NSString *loadingTitleText;


/*!
 Sets the Custom Subtitle text to be shown on the Loading Screen. If not provided, default text will be shown.
 */
@property (nullable, nonatomic) NSString *loadingSubtitleText;


/*!
 Sets the application group identifier of the form of "group.com.mycompanyname". If not provided, default will be nil.
 Used for saving the SQLite Persistent Store in a shared app folder which can be accessed by multiple targets & extensions.
 */
@property (nullable, nonatomic) NSString *appGroupIdentifier;


/*!
 Gets the navigation bar tint color used for tinting on individual screens.
 To set a tint color, use as -
 
 @code
 
 [[Haptik sharedSDK] configureNavigationBarWithTintColor:[UIColor blackColor]];
 
 @endcode
 */
@property (nonatomic, readonly) UIColor *navigationBarTintColor;


/*!
 Gets the API key for the current app. This should only be called after the SDK has been initialized otherwise will return nil
 */
@property (nonatomic, readonly) NSString *apiKey;


/*!
 Gets the base endpoint to use. This should only be called after the SDK has been initialized otherwise will return nil
 */
@property (nonatomic, readonly) NSString *baseUrl;


/*!
 Gets the client id for the current app. This should only be called after the SDK has been initialized otherwise will return nil
 */
@property (nonatomic, readonly) NSString *clientID;


/*!
 Gets the run environment of the SDK. This should only be called after the SDK has been initialized otherwise will return HaptikLibEnvProduction(== 0)
 */
@property (nonatomic, readonly) HaptikLibRunEnvironment runEnvironment;


#pragma mark - SDK Signup Helpers

/*!
 @method
 SignIn the User with SignUp Data.
 
 @param signUpData   Object of HPSignUpObject
 @param completion   Completion Handler which will have the success or error information.
 
 @code
 
 HPSignUpObject *signupObj = [HPSignUpObject buildWith:@"AUTH_TYPE_HERE" data:^(HPSignUpBuilder * _Nonnull builder) {
 
     builder.userFullName = @"John Appleseed";
     builder.userPhoneNumber = @"9870000000";
     builder.userEmail = @"john@apple.com";
     builder.userCity = @"Mumbai";
     builder.authToken = @"";
 }];
 
 [[Haptik sharedSDK] signUpWith:signupObj completion:^(BOOL success, UIViewController * _Nullable initialVC, NSError * _Nullable error) {
 
     dispatch_async(dispatch_get_main_queue(), ^{
 
         if (success) {
 
             [self.navigationController pushViewController:initialVC animated:YES];
         }
         else {
             UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Oops!"
             message:error.localizedDescription
             preferredStyle:UIAlertControllerStyleAlert];
 
             UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:nil];
             [alert addAction:action];
             [self presentViewController:alert animated:YES completion:nil];
         }
     });
 }];
 
 @endcode
 */
- (void)signUpWith:(HPSignUpObject *)signUpData
        completion:(void (^)(BOOL success,__kindof UIViewController * _Nullable initialVC, NSError * _Nullable error))completion;


/*!
 @abstract
 SignIn the User with SignUp Data.
 
 @discussion
 This function immediately returns the Initial View Controller. The loading view will be shown till the inital data is synced. If an error comes up, the user will be popped back.
 
 @param signUpData  Object of HPSignUpObject
 @param completion  Completion Handler which will have the success or error information.
 
 @code
 
 HPSignUpObject *signupObj = [HPSignUpObject buildWith:@"AUTH_TYPE_HERE" data:^(HPSignUpBuilder * _Nonnull builder) {
 
     builder.userFullName = @"John Appleseed";
     builder.userPhoneNumber = @"9870000000";
     builder.userEmail = @"john@apple.com";
     builder.userCity = @"Mumbai";
     builder.authToken = @"";
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
- (__kindof UIViewController *_Nullable)signUpWithLoadingScreenFor:(HPSignUpObject *)signUpData
                                                        completion:(void (^)(BOOL success, NSError * _Nullable error))completion;


/*!
 @abstract
 SignIn the User with SSO.
 
 @discussion
 The user will be signed up with Basic Auth Type if the details are not available on SSO else the user will be signed up using SSO.
 This function immediately returns the Initial View Controller. The loading view will be shown till the inital data is synced. If an error comes up, the user will be popped back.
 
 @param completion  Completion Handler which will have the success or error information.
 
 @code
 
 UIViewController *initialVC = [[Haptik sharedSDK] signUpUserWithSSO:^(BOOL success, NSError * _Nullable error) {
 
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
- (__kindof UIViewController *_Nullable)signUpUserWithSSO:(void (^)(BOOL success, NSError * _Nullable error))completion;


/*!
 @method
 Update an user's details with an existing unique identifier.
 Doesn't requires the user to perform OTP verification.
 */
- (void)updateExistingUserWith:(NSDictionary<NSString *, NSString *> *)data
                    completion:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))completion;;

/*!
 @method
 Returns a Bool indicating if the user is already signed up or not.
 */
- (BOOL)isUserSignedUp;


/*!
 @method
 Returns the Initial View Controller if the User has already signed up.
 
 @code
 
 #import "MyViewController.h"
 
 - (void)launchInbox:(UIButton *)sender {
 
     if ([[Haptik sharedSDK] isUserSignedUp]) {
 
         UIViewController *initialVC = [[Haptik sharedSDK] getInitialVC];
 
         [self.navigationController pushViewController:initialVC animated:YES];
     }
 }
 
 @endcode
 */
- (__kindof UIViewController * _Nullable)getInitialVC;


/*!
 @abstract
 Update user token of logged in user.
 
 @param token       Token that need to be updated.
 @param authID      AuthenticationID of the loggedIn user.
 @param authType    AuthenticationType of the loggedIn user.
 @param completion  Completion Handler which will have the success information.
 
 @code
 
 [[Haptik sharedSDK] updateUserToken:@"Updated Auth Token/Code"
                              authID:@"User's Auth ID"
                            authType:@"User's Auth Type"
                          completion:^(BOOL success) {
 
     if (success) {
 
     } else {

     }
 }];
 
 @endcode
 */
- (void)updateUserToken:(NSString *)token
                 authID:(NSString *)authID
               authType:(NSString *)authType
             completion:(void (^)(BOOL success))completion;


/*!
 @method
 Notify the Haptik SDK of application launch
 @param application Your singleton app object
 @param launchOptions A dictionary indicating the reason the app was launched (if any). The contents of this dictionary may be empty in situations where the user launched the app directly.
 
 @code
 
 #import "AppDelegate.h"
 
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    ...
    [[Haptik sharedSDK] notifyApplication:application launchedWithOptions:launchOptions];
 }
 
 @endcode
 */
- (void)notifyApplication:(UIApplication *)application launchedWithOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions;


#pragma mark - SDK Signout Helpers

/*!
 @method
 Signouts the current user from Haptik
 
 @param completion  Completion Handler which will have the success information.
 
 @code
 
 [[Haptik sharedSDK] signoutFromHaptik:^(BOOL success, NSError * _Nullable error) {
 
     if (success) {
 
     }
     else {
 
     }
 }];
 
 @endcode
 */
- (void)signoutFromHaptik:(void (^)(BOOL success, NSError * _Nullable error))completion;


#pragma mark - Haptik Wallet

/*!
 @method
 Returns boolean value indicating if User's Haptik Wallet has been created or not.
 */
- (BOOL)isHaptikWalletCreated;


/*!
 @method
 Returns String value of User's Haptik Wallet Balance. Will return nil if:
 - User's wallet has not been created yet.
 - Haptik Wallet Servers are currently down.
 */
- (NSString *)getHaptikWalletBalance;


/*!
    @method
    By calling this method you will get an instance of Haptik Wallet Screen.

    @param defaultsToHistory    A boolean indicating whether the wallet history tab should be selected by default or not.
    @param delegate     If shouldUseReferrals property of Haptik is set to true, then the delegate will pass the callbacks when the Share and Earn View is Tapped in the Wallet Scene.
 
 @code
 
 #import "MyViewController.h"
 
 __weak typeof(self) weakSelf = self;
 
 [[Haptik sharedSDK] getHaptikWalletViewController:NO
                              shareAndEarnDelegate:nil
                                        controller:weakSelf
                                        completion:^(BOOL success, __kindof UIViewController * _Nullable haptikWalletVC) {
 
     typeof(self) strongSelf = weakSelf;

     if (success) {
         [strongSelf.navigationController pushViewController:haptikWalletVC animated:YES];
     }
 }];
 
 @endcode
 */
- (void)getHaptikWalletViewController:(BOOL)defaultsToHistory
                 shareAndEarnDelegate:(nullable id <HPShareAndEarnDelegate>)delegate
                           controller:(__kindof UIViewController *__weak)controller
                           completion:(void(^)(BOOL success, __kindof UIViewController *_Nullable haptikWalletVC))completion;


#pragma mark - Referral Code

/*!
 @method
 By calling this method you will get an instance of ReferralCode Sene.
 
 @param mobileNumber    If applying referral code before signup, pass the users mobile number else, nil
 @param delegate        ReferalCodeDelegate, if passed and confirmed, will give callback after applying and success of it.
 
 @code
 
 #import "MyViewController.h"
 
 UIViewController *controller = [[Haptik sharedSDK] getReferralCodeViewControllerFor:@"MOBILE_NO" referralDelegate:self];
 
 [self.navigationController pushViewController:controller animated:YES]
 
 @endcode
 */
- (__kindof UIViewController * _Nullable)getReferralCodeViewControllerFor:(nullable NSString *)mobileNumber
                                                         referralDelegate:(nullable id <ReferalCodeDelegate>)delegate;


#pragma mark - Current Offers

/*!
 @method
 By calling this method you will get current offers count
 */
- (NSUInteger)getOffersCount;


/*!
 @method
 By calling this method you will get an instance of Offers Screen.
 
 @code
 
 UIViewController *offersVC = [[Haptik sharedSDK] getOffersViewContoller];
 [delegateController.navigationController pushViewController:offersVC animated:YES];
 
 @endcode
 */
- (__kindof UIViewController *_Nullable)getOffersViewContoller;


#pragma mark - Remote Notifications

/*!
 @method
 
 @abstract
 Register the device to receive push notifications.
 
 @discussion
 This will associate the device token with the current user to allow push notifications to the user.
 
 @param deviceToken  device token as returned from application:didRegisterForRemoteNotificationsWithDeviceToken:
 
 @code
 
 #import "MyAppDelegate.h"
 
 - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
 
    ...
 
    [[Haptik sharedSDK] setDeviceToken:deviceToken];
 }
 
 @endcode
 */
- (void)setDeviceToken:(NSData *)deviceToken;


/*!
 @method
 
 @abstract
 Specifies to caller that whether passed in notification payload can be processed by Haptik SDK. This will immediately return boolean indicating if the remote notification payload received is from Haptik SDK.
 
 @param userInfo     The received remote notification payload to be processed
 @return    Returns a BOOL indicating indicating the payload will be handled by HaptikLib
 
 @code
 
 #import "MyAppDelegate.h"
 
 // For iOS 10.x & later
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center
    didReceiveNotificationResponse:(UNNotificationResponse *)response
             withCompletionHandler:(void(^)(void))completionHandler {
 
     ...
 
     BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:response.notification.request.content.userInfo];
 
     if (canBeHandledByHaptik) {
        NSLog(@"do housekeeping");
        [[Haptik sharedSDK] handleNotificationWithUserInfo:response.notification.request.content.userInfo controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
     }
 }
 
 // For iOS 9.x
 - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
 
     ...
 
     BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];
 
     if (canBeHandledByHaptik) {
        NSLog(@"do housekeeping");
     }
 }
 
 // optional
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center
        willPresentNotification:(UNNotification *)notification
          withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
 
     ...
 
     BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:response.notification.request.content.userInfo];
 
     if (canBeHandledByHaptik) {
         NSLog(@"do housekeeping");
         [[Haptik sharedSDK] handleNotificationWithUserInfo:response.notification.request.content.userInfo controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
     }
 }
 
 @endcode
 */
- (BOOL)canHandleNotificationWithUserInfo:(NSDictionary<NSString *, id> *)userInfo;


/*!
 @method
 
 @abstract
 Informs the caller whether passed notification userinfo payload can be handled by HaptikLib.
 
 @discussion
 If YES, the payload is processed by HaptikLib.
 
 
 @param userInfo     The received remote notification payload to be processed
 @param controller   The current view controller over which the notification is expected to be handled
 @return    Returns a BOOL indicating indicating the payload will be handled by HaptikLib
 
 @code
 
 #import "MyAppDelegate.h"
 
 // For iOS 10.x & later
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center
    didReceiveNotificationResponse:(UNNotificationResponse *)response
             withCompletionHandler:(void(^)(void))completionHandler {
 
    ...
 
     BOOL isHandledByHaptik = [[Haptik sharedSDK] handleNotificationWithUserInfo:response.notification.request.content.userInfo controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
 
     if (isHandledByHaptik) {
         NSLog(@"do housekeeping");
     }
 }
 
 // For iOS 9.x
 - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
 
    ...
 
    [[Haptik sharedSDK] handleNotificationWithUserInfo:userInfo controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
 }
 
 // optional
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center
        willPresentNotification:(UNNotification *)notification
          withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
 
    ...
 
    [[Haptik sharedSDK] handleNotificationWithUserInfo:notification.request.content.userInfo controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
 }
 
 @endcode
 */
- (BOOL)handleNotificationWithUserInfo:(NSDictionary<NSString *, id> *)userInfo
                            controller:(__kindof UIViewController *)controller;


#pragma mark -

/*!
 @abstract
 Allows SDK Clients to modify tint color and barTintColor of navigation bar of the SDK View Controllers
 
 @param tintColor Color to be used for tinting navigation bar items. Defaults to [UIColor blackColor].
 @param barTintColor Color to be used for tinting the navigation bar. Defaults to default navigation bar tint of iOS
 @param translucent BOOL value to set the translucent property of navigation bar.
 @param navigationController Instance of the navigationController for which the configurations are to be done
 
 @discussion
 The params tintColor & barTintColor are nullable, i.e. you can pass nil for the respective param which you want to set to default (don't want to set).
 
 @code
 
 [[Haptik sharedSDK] configureNavigationBarWithTintColor:[UIColor redColor]
                                            barTintColor:[UIColor whiteColor]
                                 forNavigationController:navController];
 
 @endcode
 */
- (void)configureNavigationBarWithTintColor:(nullable UIColor *)tintColor
                               barTintColor:(nullable UIColor *)barTintColor
                            makeTranslucent:(BOOL)translucent
                      forNavigationController:(UINavigationController *)navigationController;


/*!
 Allows SDK clients to take user to a specific channel.
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param message String message to be sent from user-side on opening channel screen
 @param controller The current view controller over which the channel is expected to be pushed
 
 @code
 
 #import "MyViewController.h"
 
 - (void)openChannelInHaptik {
 
    [[Haptik sharedSDK] launchChannelWith:@"mychannelinhaptik"
                                  message:@"We wish you have a good time using this SDK"
                               controller:self];
 }
 
 @endcode
 */
- (void)launchChannelWith:(NSString *)viaName
                  message:(nullable NSString *)message
               controller:(__kindof UIViewController *)controller;


/*!
 Allows SDK clients to take user to a specific channel and trigger the Bot
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param message String message to be sent to the backend on opening channel screen
 @param source Represents the source from where the specific channel is launched and the Bot is triggered
 @param controller The current view controller over which the channel is expected to be presented
 
 @code
 
 #import "MyViewController.h"
 
 - (void)openChannelInHaptikAndTriggerBot {
 
 [[Haptik sharedSDK] launchChannelToTriggerBotFor:@"mychannelinhaptik"
                                           message:@"MESSAGE_FOR_TRIGGERING_BOT"
                                            source:@"SOURCE_HERE"
                                        controller:self];
 }
 
 @endcode
 */
- (void)launchChannelToTriggerBotFor:(NSString *)viaName
                               message:(nullable NSString *)message                           
                                source:(NSString *)source
               controller:(__kindof UIViewController *)controller;


/*!
 Specifies whether Haptik Lib will handle URL redirects
 @param url  The url expected to be handled
 @param options  A dictionary of URL handling options
 
 @code
 
 #import "MyAppDelegate.h"
 
 - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
     return [[Haptik sharedSDK] isRedirectHandled:url options:options];
 }
 
 @endcode
 */
- (BOOL)isRedirectHandled:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;


/*!
 @method
 By calling this method you will get an instance of Transaction History Screen.
 
 @code
 
 #import "MyViewController.h"
 
 __weak typeof(self) weakSelf = self;
 
 [[Haptik sharedSDK] getTransactionHistoryFor:weakSelf
                                   completion:^(BOOL success, __kindof UIViewController * _Nullable transactionsVC) {
 
     typeof(self) strongSelf = weakSelf;
 
     if (success) {
         [strongSelf.navigationController pushViewController:transactionsVC animated:YES];
     }
 }];
 
 @endcode
 */
- (void)getTransactionHistoryFor:(__kindof UIViewController *__weak)controller
                      completion:(void(^)(BOOL success, __kindof UIViewController *_Nullable transactionsVC))completion;


/*!
 @method
 By calling this method you will get the Unread Count of the Users Inbox Chats.
 */
- (void)getUnreadCountWithCompletion:(void(^)(NSUInteger unreadCount))completion;


/*!
 @method
 By calling this method you will get an instance of User Details Screen
 
 @code
 
 #import "MyViewController.h"
 
 UIViewController *viewController = [[Haptik sharedSDK] getUserDetailsScreen];
 if (viewController) {
     [self.navigationController pushViewController:viewController animated:YES];
 }
 
 @endcode
 */
- (nullable __kindof UIViewController *)getUserDetailsScreen;

@end


NS_ASSUME_NONNULL_END

