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

@class HPSignUpObject;


NS_ASSUME_NONNULL_BEGIN


#pragma mark - Run Environment

typedef NS_ENUM(NSUInteger, HaptikLibRunEnvironment) {
    
    HaptikLibEnvProduction = 0,
    HaptikLibEnvStage,
    HaptikLibEnvDevelopment
};


#pragma mark -

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


#pragma mark - Attributes

/*!
 Gets the client id for the current app. This should only be called after the SDK has been initialized otherwise will return nil
 */
@property (nonatomic, readonly) NSString *clientID;


/*!
 Gets the base endpoint to use. This should only be called after the SDK has been initialized otherwise will return nil
 */
@property (nonatomic, readonly) NSString *baseUrl;


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

    @param showHistory    A boolean indicating whether the wallet history tab should be selected by default or not.
 
 @code
 
 #import "MyViewController.h"
 
 [[Haptik sharedSDK] pushToHaptikWalletFrom:self
                                showHistory:NO
                                completion:^(BOOL success) {

     if (success) {
        NSLog(@"do housekeeping");
     }
 }];
 
 @endcode
 */
- (void)pushToHaptikWalletFrom:(__kindof UIViewController *__weak)sourceController
                   showHistory:(BOOL)showHistory
                    completion:(void(^ _Nullable)(BOOL success))completion;


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
 
 [[Haptik sharedSDK] pushToTransactionHistoryFrom:self
                                       completion:^(BOOL success) {
 
         if (success) {
             NSLog(@"do housekeeping");
         }
 }];
 
 @endcode
 */
- (void)pushToTransactionHistoryFrom:(__kindof UIViewController *__weak)sourceController
                          completion:(void(^ _Nullable)(BOOL success))completion;


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

