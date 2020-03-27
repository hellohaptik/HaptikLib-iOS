//
//  Haptik.h
//  HaptikLib - Haptik Personal Assistant SDK for iOS
//
//  Copyright © 2020 Haptik. All rights reserved.
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
    HaptikLibEnvStage
};


#pragma mark - HaptikLib Interface

@interface Haptik : NSObject

/**
 Returns the Haptik singleton object
 */
+ (instancetype)sharedSDK;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Launch Methods

/**
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
- (void)notifyApplication:(UIApplication *)application launchedWithOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions  __attribute__((deprecated("This method is no longer required to be implemented and can be removed.")));


#pragma mark - Signup/Signout Methods

/**
 @method
 Returns a Bool indicating if the user is already signed up or not.
 
 @abstract
 For you to take the user to the conversation screen where the user interracts/chats with the bot/agent, you first need to signup the user into haptik first.
 This method tells you if currently any user is signed up in haptik or not.
 
 @code
 
    // You can check this from where ever you are taking the user to Haptik's conversation screen
 
     if ([Haptik sharedSDK].isUserSignedUp) {
         
         // Take the user to the haptik conversation screen using the unique viaName provided to you.
     }
     else {
         
         // First signup the user into haptik, post that take the user to the haptik conversation screen using the unique viaName provided to you.
     }
 
 @endcode
 */
- (BOOL)isUserSignedUp;

/**
 @method
 Signup the user into haptik with SignUp Data.
 
 @abstract
 Use this method to signup the user to Haptik. You can pass along meta data for the user during the signup using the HPSignupBuilder.
 It returns the completion on the mainQueue.
 
 @param signUpData   Object of HPSignUpObject
 @param completion   Completion Handler which will have the success or error information and is returned on the mainQueue.
 
 @code
 
 HPSignUpObject *signupObj = [HPSignUpObject buildWithAuthType:@"AUTH_TYPE_HERE"
                                                          data:^(HPSignUpBuilder * _Nonnull builder) {
 
    builder.userFullName = @"John Appleseed";
    builder.userPhoneNumber = @"9870000000";
    builder.userEmail = @"john@apple.com";
    builder.authToken = @"";
    builder.authID = @"";
    builder.viaName = @"mychannelinhaptik";
    builder.launchMessage = @"Hey!";
    builder.hideLaunchMessage = YES;
    builder.customData = @{@"Key": @"Value", @"Key": @"Value"};
 }];
 
 [[Haptik sharedSDK] signUpWith:signupObj
                     completion:^(BOOL success, __kindof UIViewController * _Nullable viewController, NSError * _Nullable error) {
 
     if (success) {
 
        // If via name is provided then after signup,
        // the SDK will give back an instance of the haptik's conversation controller that you can directly push the user too.
 
        [self.navigationController pushViewController:viewController animated:YES];
     }
     else {
     
         // Handle error here
     }
 }];
 
 @endcode
 */
- (void)signUpWith:(HPSignUpObject *)signUpData
        completion:(void (^)(BOOL success, __kindof UIViewController * _Nullable viewController, NSError * _Nullable error))completion;

/**
 @method
 Signouts the current user from Haptik.
 
 @abstract
 Use this method to signout the user from Haptik. All of the user's data and chat history will be deleted from the SDK.
 The Haptik SDK maintains all the user data and chat data until you call signout.
 You'll probably need to call it whenever you signout the user from your application.
 It returns the completion on the mainQueue.
 
 @param completion  Completion Handler which will have the success information and is returned on the mainQueue.
 
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


#pragma mark - Conversation

/**
 @method
 Take the user to your conversation using the unique viaName provided to you by Haptik.
 
 @abstract
 It takes an instance of the current view controller and the unique viaName provided to you and pushes the haptik's conversation controller over your navigation stack.
 You can choose to send a message to haptik from the user side everytime you take the user to the screen. If passed nil or empty no message will be sent.
 You also have the capability to hide the launch message (pass hideLaunchMessage as YES) from the conversation, but it'll still be sent to haptik's backend.
 Think of it like a silent message which can be used to give some context to the bot.
 
 Note: If the passed via name is not correct then the operation will fail silently.
 
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param message String message to be sent from user-side on opening channel screen
 @param hideLaunchMessage If NO,  will display the message as a part of the chat, else it'll send the message without displaying it to the user
 @param controller The current view controller over which the channel is expected to be pushed
 
 @code
 
 #import "MyViewController.h"
 
 - (void)pushToHaptikConversation {
 
     [[Haptik sharedSDK] launchChannelWith:@"mychannelinhaptik"
                             launchMessage:@"Hey!"
                         hideLaunchMessage:NO
                                controller:self];
 }
 
 @endcode
 */
- (void)launchChannelWith:(NSString *)viaName
            launchMessage:(nullable NSString *)message
        hideLaunchMessage:(BOOL)hideLaunchMessage
               controller:(__kindof UIViewController *)controller;

/**
 @method
 Take the user to your conversation using the unique viaName provided to you by Haptik.
 
 @abstract
 It takes an instance of the current view controller and the unique viaName provided to you and pushes the haptik's conversation controller over your navigation stack.
 You can choose to send a message to haptik from the user side everytime you take the user to the screen. If passed nil or empty no message will be sent.
 
 Note: If the passed via name is not correct then the operation will fail silently.
 
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param message String message to be sent from user-side on opening channel screen
 @param controller The current view controller over which the channel is expected to be pushed
 */
- (void)launchChannelWith:(NSString *)viaName
                  message:(nullable NSString *)message
               controller:(__kindof UIViewController *)controller __attribute__((deprecated("Use launchChannelWith:launchMessage:hideLaunchMessage:controller: instead")));

/**
 @method
 Gets you an instance of the conversation controller using the unique viaName provided to you by Haptik.
 
 @abstract
 It gives you an instance of the conversation controller using the unique viaName provided to you. If the viaName is not correct the error object is populated.
 You can choose to send a message to haptik from the user side everytime you take the user to the screen. If passed nil or empty no message will be sent.
 You also have the capability to hide the launch message (pass hideLaunchMessage as YES) from the conversation, but it'll still be sent to haptik's backend.
 Think of it like a silent message which can be used to give some context to the bot.
 The message sending will be done after you present or push the haptik's conversation screen.
 
 @code
 
 - (void)pushToHaptikConversation {
     
     NSError *error;
     UIViewController *conversation = [[Haptik sharedSDK] getConversationForViaName:@""
                                                                      launchMessage:@"Hey!"
                                                                  hideLaunchMessage:NO
                                                                              error:&error];
     
     if (conversation) {
         [self.navigationController pushViewController:conversation animated:YES];
     }
     else {
         // Handle Error.
     }
 }

 @endcode
 
 @param viaName Represents the key that haptik uses to find your conversation
 @param message String message to be sent from user-side on opening channel screen
 @param hideLaunchMessage If NO,  will display the message as a part of the chat, else it'lll send the message without displaying it to the user
 @param error It requires an NSError object pointer that will be populated in case of a potential fail during the process
 */
- (__kindof UIViewController * _Nullable)getConversationForViaName:(NSString *)viaName
                                                     launchMessage:(nullable NSString *)message
                                                 hideLaunchMessage:(BOOL)hideLaunchMessage
                                                             error:(NSError * __autoreleasing *)error;

/**
 @method
 Gets you an instance of the conversation controller using the unique viaName provided to you by Haptik.

 @abstract
 It gives you an instance of the conversation controller using the unique viaName provided to you. If the viaName is not correct the error object is populated.

 @code

 - (void)pushToHaptikConversation {
    
        NSError *error;
        UIViewController *conversation = [[Haptik sharedSDK] getConversationForViaName:@""
                                                                                 error:&error];
    
        if (conversation) {
            [self.navigationController pushViewController:conversation animated:YES];
        }
        else {
            // Handle Error.
        }
 }

 @endcode

 @param viaName Represents the key that haptik uses to find your conversation
 @param error It requires an NSError object pointer that will be populated in case of a potential fail during the process
 */
- (__kindof UIViewController * _Nullable)getConversationForViaName:(NSString *)viaName
                                                             error:(NSError * __autoreleasing *)error __attribute__((deprecated("Use getConversationForViaName:launchMessage:hideLaunchMessage:error: instead")));

/**
 @method
 Take the user to your conversation using the unique viaName provided to you by Haptik trigger the Bot.
 
 @abstract
 It takes an instance of the current view controller and the unique viaName provided to you and pushes the haptik's conversation controller over your navigation stack.
 The message will be sent silently to haptik (if not empty or nil) to give context to the bot and trigger it.
 
 Note: If the passed via name is not correct then the operation will fail silently.
 
 @code
 
 #import "MyViewController.h"
 
 - (void)openChannelInHaptikAndTriggerBot {
 
     [[Haptik sharedSDK] launchChannelToTriggerBotFor:@"mychannelinhaptik"
                                              message:@"MESSAGE_FOR_TRIGGERING_BOT"
                                               source:@"SOURCE_HERE"
                                        mmmcontroller:self];
 }
 
 @endcode
 
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param message String message to be sent to the backend on opening channel screen
 @param source Represents the source from where the specific channel is launched and the Bot is triggered
 @param controller The current view controller over which the channel is expected to be presented
 */
- (void)launchChannelToTriggerBotFor:(NSString *)viaName
                             message:(nullable NSString *)message
                              source:(NSString *)source
                          controller:(__kindof UIViewController *)controller;


#pragma mark - Remote Notifications

/**
 @method
 
 @abstract
 Register the device to receive push notifications from haptik conversation
 
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

/**
 @method
 
 @abstract
 Register the device to receive push notifications from haptik conversation
 
 @discussion
 This will associate the device token with the current user to allow push notifications to the user.
 
 @param deviceToken device token as returned from application:didRegisterForRemoteNotificationsWithDeviceToken: converted to an NSString.
 */
- (void)setDeviceTokenAsString:(NSString *)deviceToken;

/**
 @method
 
 @abstract
 Specifies to caller that whether passed in notification payload can be processed by Haptik SDK. This will immediately return boolean indicating if the remote notification payload received is from Haptik SDK.
 
 @param userInfo    The received remote notification payload to be processed
 @return    Returns a BOOL indicating indicating the payload will be handled by HaptikLib
 
 @code
 
 #import "MyAppDelegate.h"
 
 // For iOS 9.x
 - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
 
    ...
    BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];
    
    if (canBeHandledByHaptik) {
        NSLog(@"do housekeeping");
    }
    
    [[Haptik sharedSDK] didReceiveHaptikRemoteNotification:userInfo controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
 }
 
 @endcode
 */
- (BOOL)canHandleNotificationWithUserInfo:(NSDictionary<NSString *, id> *)userInfo;

/**
@method

@abstract
Specifies to caller that whether passed in notification payload can be processed by Haptik SDK. This will immediately return boolean indicating if the remote notification payload received is from Haptik SDK.

@param response The received remote notification UNNotificationResponse to be processed
@return Returns a BOOL indicating indicating the payload will be handled by HaptikLib

@code

#import "MyAppDelegate.h"

// For iOS 10.x & later
- (void)userNotificationCenter:(UNUserNotificationCenter *)center  didReceiveNotificationResponse:(UNNotificationResponse *)response
         withCompletionHandler:(void(^)(void))completionHandler {
    ...
    
    BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithResponse:response];
    
    if (canBeHandledByHaptik) {
    
       NSLog(@"do housekeeping");
       [[Haptik sharedSDK] didReceiveHaptikNotificationResponse:response
                                                     controller:((UINavigationController *)self.window.rootViewController).visibleViewController];
       }
}

@endcode
*/
- (BOOL)canHandleNotificationWithResponse:(UNNotificationResponse *)response;

/**
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

/**
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

/**
@method

@abstract
Prepares the HaptikSDK to handle the notification and gives you back the viaName of the conversation that the message belongs too.
 
@discussion
This method comes to use If you want to handle the notifications flow by yourself. On tapping the Haptik Notification, if you yourself want to take the user to the conversation, call this method before doing that.
It returns the viaName of the conversation to which the notification belongs too. Using this extracted viaName, you can take the user to the conversation scree.

@param response     The received remote notification UNNotificationResponse to be processed
@return Returns the viaName of the conversation where you should take the user. Will return nil if its not an haptik notification

@code

 - (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response
          withCompletionHandler:(void(^)(void))completionHandler {
             
     if ([[Haptik sharedSDK] canHandleNotificationWithResponse:response]) {
         
         NSString *viaName = [[Haptik sharedSDK] prepareHaptikNotificationForResponse:response];
         
         if (viaName && ![visibleViewController isKindOfClass:HPConversationClass()]) {
             [[Haptik sharedSDK] launchChannelWith:viaName launchMessage:@"" hideLaunchMessage:NO controller:visibleViewController];
         }
     }
     
     completionHandler();
 }

@endcode
*/
- (NSString * _Nullable)prepareHaptikNotificationForResponse:(UNNotificationResponse *)response;


#pragma mark - Additional Methods

/**
 @method
 Updates the user's authentication credentials if expired.
 
 @abstract
 Update user authentication credentials with the new ones.
 It returns the completion on the mainQueue.
 
 @param token   Token that need to be updated.
 @param authID  AuthenticationID of the loggedIn user.
 @param authType    AuthenticationType of the loggedIn user.
 @param completion  Completion Handler which will have the success information and is returned on the mainQueue.
 
 @code
 
 [[Haptik sharedSDK] updateUserToken:@"Updated Auth Token/Code"
                              authID:@"User's Auth ID"
                            authType:@"User's Auth Type"
                          completion:^(BOOL success) {
 
            if (success) {
         
            }
            else {

            }
 }];
 
 @endcode
 */
- (void)updateUserToken:(NSString *)token
                 authID:(NSString *)authID
               authType:(NSString *)authType
             completion:(void (^)(BOOL success))completion;

/**
 @method
 Let's you sync some custom data with the backend for the signed in user to give the bot/agent some context.
 
 @abstract
 Use this method if you have any requirement to send any related/necessary data to the backend for the bot/agent to take into account for the conversation before taking the user to the conversation screen.
 The completion is returned on mainQueue.
 
 Note: You can also pass this customData during the signup also by setting it in the HPSignupObject's customData property. This method updates over the key values if already present in the backend else creates them.
 
 @code
 
 [[Haptik sharedSDK] syncUserCustomData:@{@"key": @"value", @"key": @"value"}
                             completion:^(BOOL success, NSError * _Nullable error) {
     
     [[Haptik sharedSDK] launchChannelWith:@"mychannelinhaptik"
                             launchMessage:@"Hey!"
                         hideLaunchMessage:NO
                                controller:self];
 }];
 
 @endcode
 
 @param data Custom data needed to be updated for the user
 @param completion Completion Handler which will have the success and error information and is returned on the mainQueue.
 */
- (void)syncUserCustomData:(NSDictionary<NSString *, NSString *> *)data
                completion:(nullable void(^)(BOOL success, NSError * _Nullable error))completion;

/**
 @method
 Calling this method will get you the count of the messages that the user hasn't read in the conversation identified by the uniquie viaName.
 The completion is returned on mainQueue.
 
 @param viaName Represents the string key used to uniquely specify channel inside Haptik
 @param completion this will be called with  an NSUInteger for number of unread messages,  an optional error object which will be populated in case of failure else nil be returned. It's returned on the mainQueue.
 */
- (void)getUnreadCountFor:(NSString *)viaName
           WithCompletion:(void(^)(NSUInteger unreadCount, NSError * _Nullable error))completion;

@end


#pragma mark - Conversation Helpers

/**
 Represents the Class object of the Haptik's Conversation
 */
Class HPConversationClass(void);

/**
 @abstract
 Checks if the conversation controller belongs to the viaName. The contoller passed should belong to the HPConversationClass.
 
 @param viaName Represents the string key used to uniquely identify a conversation inside Haptik
 @param conversationController ViewController of type HPConversationClass
 @return YES if the conversation is tied to the unique viaName passed, else NO.
 */
BOOL HPCheckConversationForViaName(NSString *viaName, __kindof UIViewController *conversationController);


NS_ASSUME_NONNULL_END

