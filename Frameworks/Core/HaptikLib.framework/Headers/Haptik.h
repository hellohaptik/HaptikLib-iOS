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
@class UNNotificationResponse;


NS_ASSUME_NONNULL_BEGIN


#pragma mark - Run Environment

typedef NS_ENUM(NSUInteger, HaptikLibRunEnvironment) {
    
    HaptikLibEnvProduction = 0,
    HaptikLibEnvStage,
    HaptikLibEnvDevelopment
};


#pragma mark -



@interface Haptik : NSObject

/*!
 Returns the Haptik singleton object
 */
+ (instancetype)sharedSDK;


- (instancetype)init NS_UNAVAILABLE;


#pragma mark - SDK Signup Helpers

/*!
 @method
 SignIn the User with SignUp Data.
 
 @param signUpData   Object of HPSignUpObject
 @param completion   Completion Handler which will have the success or error information.
 
 @code
 
 HPSignUpObject *signupObj = [HPSignUpObject buildWithAuthType:@"AUTH_TYPE_HERE"
                                                          data:^(HPSignUpBuilder * _Nonnull builder) {
 
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
- (void)signUpWith:(HPSignUpObject *)signUpData
        completion:(void (^)(BOOL success, __kindof UIViewController * _Nullable viewController, NSError * _Nullable error))completion;

/*!
 @method
 Returns a Bool indicating if the user is already signed up or not.
 */
- (BOOL)isUserSignedUp;

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
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center  didReceiveNotificationResponse:(UNNotificationResponse *)response
          withCompletionHandler:(void(^)(void))completionHandler {
 
 ...
 
 BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];
 
 if (canBeHandledByHaptik) {
 
    NSLog(@"do housekeeping");
    [[Haptik sharedSDK] didReceiveHaptikNotificationResponse:response
                                                  controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
    }
 }
 
 // For iOS 9.x
 - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
 
 ...
 
 BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];
 
 if (canBeHandledByHaptik) {
 
    NSLog(@"do housekeeping");
    [[Haptik sharedSDK] didReceiveHaptikNotificationResponse:response
                                                  controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
    }
 }
 
 @endcode
 */
- (BOOL)canHandleNotificationWithUserInfo:(NSDictionary<NSString *, id> *)userInfo;


/*!
 @method
 
 @abstract
 Handles the Haptik notification when the user responded to the notification by opening the application, dismissing the notification or choosing a UNNotificationAction.
 
 @param response     The received remote notification UNNotificationResponse to be processed
 @param controller   The current view controller over which the notification is expected to be handled
 
 @code
 
 #import "MyAppDelegate.h"
 
 // For iOS 10.x & later
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center      didReceiveNotificationResponse:(UNNotificationResponse *)response
          withCompletionHandler:(void(^)(void))completionHandler {
 
 ...
 
 BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];
 
 if (canBeHandledByHaptik) {
 
    NSLog(@"do housekeeping");
    [[Haptik sharedSDK] didReceiveHaptikNotificationResponse:response
                                                  controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
    }
 }
 
 @endcode
 */
- (void)didReceiveHaptikNotificationResponse:(UNNotificationResponse *)response
                                  controller:(__kindof UIViewController *)controller;

/*!
 @method
 
 @abstract
 Handles the Haptik notification when the user responded to the notification by opening the application from background or killed state.
 
 @param userInfo     The received remote notification userInfo to be processed
 @param controller   The current view controller over which the notification is expected to be handled
 
 @code
 
 #import "MyAppDelegate.h"
 
 // For iOS 9.x
 - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
 
 ...
 
 BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];
 
 if (canBeHandledByHaptik) {
 
    NSLog(@"do housekeeping");
    [[Haptik sharedSDK] didReceiveHaptikRemoteNotification:userInfo
                                                controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
    }
 }
 
 @endcode
 */
- (void)didReceiveHaptikRemoteNotification:(NSDictionary<NSString *, id> *)userInfo
                                controller:(__kindof UIViewController *)controller;


#pragma mark -

/**
 Allows SDK clients to take user to a specific channel.
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param message String message to be sent from user-side on opening channel screen
 @param hideLaunchMessage If YES,  will display the message as a part of the chat, else it'll send the message without displaying it to the user
 @param controller The current view controller over which the channel is expected to be pushed
 
 @code
 
 #import "MyViewController.h"
 
 - (void)openChannelInHaptik {
 
 [[Haptik sharedSDK] launchChannelWith:@"mychannelinhaptik"
                         launchMessage:@"We wish you have a good time using this SDK"
                     hideLaunchMessage:NO
                            controller:controller];
 }
 
 @endcode
 */
- (void)launchChannelWith:(NSString *)viaName
            launchMessage:(nullable NSString *)message
        hideLaunchMessage:(BOOL)hideLaunchMessage
               controller:(__kindof UIViewController *)controller;

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
               controller:(__kindof UIViewController *)controller __attribute__((deprecated("Use launchChannelWith:launchMessage:hideLaunchMessage:controller: instead")));

/// Gets you an instance of the conversation window
///
/// @param viaName Represents the key that haptik uses to find your conversation
/// @param message String message to be sent from user-side on opening channel screen
/// @param hideLaunchMessage If YES,  will display the message as a part of the chat, else it'lll send the message without displaying it to the user
/// @param error It requires an NSError object pointer that will be populated in case of a potential fail during the process
- (__kindof UIViewController * _Nullable)getConversationForViaName:(NSString *)viaName
                                                     launchMessage:(nullable NSString *)message
                                                 hideLaunchMessage:(BOOL)hideLaunchMessage
                                                             error:(NSError * __autoreleasing *)error;

/// Gets you an instance of the conversation window
///
/// @param viaName Represents the key that haptik uses to find your conversation
/// @param error It requires an NSError object pointer that will be populated in case of a potential fail during the process
- (__kindof UIViewController * _Nullable)getConversationForViaName:(NSString *)viaName
                                                             error:(NSError * __autoreleasing *)error __attribute__((deprecated("Use getConversationForViaName:launchMessage:hideLaunchMessage:error: instead")));


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
                                    mmmcontroller:self];
 }
 
 @endcode
 */
- (void)launchChannelToTriggerBotFor:(NSString *)viaName
                             message:(nullable NSString *)message
                              source:(NSString *)source
                          controller:(__kindof UIViewController *)controller;


/*!
 @method
 By calling this method you'll get the count of the messages that the user hasn't read in the conversation for the specified channel.
 
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param completion this will be called with  an NSUInteger for number of unread messages,  an optional error object which will be populated in case of failure else nil be returned
 */
- (void)getUnreadCountFor:(NSString *)viaName
           WithCompletion:(void(^)(NSUInteger unreadCount, NSError * _Nullable error))completion;


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

