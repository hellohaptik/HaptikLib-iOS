//
//  HaptikSharedConstants.h
//  HaptikBase
//
//  Created by SimranJot Singh on 22/01/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#ifndef HaptikSharedConstants_h
#define HaptikSharedConstants_h

#define HPScreenWidth UIScreen.mainScreen.bounds.size.width
#define HPScreenHeight UIScreen.mainScreen.bounds.size.height

#define HPScreenPadding MIN(HPScreenWidth*0.02,8)

#pragma mark - HaptikLib Credential Keys

FOUNDATION_EXPORT NSString *const HPCredentialsDict;
FOUNDATION_EXPORT NSString *const HPClientID;
FOUNDATION_EXPORT NSString *const HPBaseURL;
FOUNDATION_EXPORT NSString *const HPRunEnvironment;


#pragma mark - HaptikLib CleverTap Credential Keys

FOUNDATION_EXPORT NSString *const HPCleverTapDict;
FOUNDATION_EXPORT NSString *const HPCleverTapAccountID;
FOUNDATION_EXPORT NSString *const HPCleverTapToken;


#pragma mark - HaptikLib Share & Rate

FOUNDATION_EXPORT NSString *const HPShareAndRateDict;
FOUNDATION_EXPORT NSString *const HPShareText;
FOUNDATION_EXPORT NSString *const HPShareUrl;
FOUNDATION_EXPORT NSString *const HPAppStoreUrl;
FOUNDATION_EXPORT NSString *const HPITunesItemIdentifier;


#pragma mark - Assert Description Constants

FOUNDATION_EXPORT NSString *const HPLibNoCredentialsDict;
FOUNDATION_EXPORT NSString *const HPLibNoClientIDKey;
FOUNDATION_EXPORT NSString *const HPLibNoBaseURLKey;
FOUNDATION_EXPORT NSString *const HPLibNoEnvironmentKey;


#pragma mark - Network Request Type Constants

FOUNDATION_EXPORT NSString *const HPHTTPMethodGET;
FOUNDATION_EXPORT NSString *const HPHTTPMethodPUT;
FOUNDATION_EXPORT NSString *const HPHTTPMethodPOST;


#pragma mark - Notification Identifier

UIKIT_EXTERN NSNotificationName const HPInternetReachabilityChanged;
UIKIT_EXTERN NSNotificationName const HPReloadConversation;
UIKIT_EXTERN NSNotificationName const HPTTSQueueFinishedPlayingEnqueuedItems;
UIKIT_EXTERN NSNotificationName const HPLanguageChanged;


#pragma mark - Enum Declarations

typedef NS_ENUM(NSUInteger, HPModuleType) {
    
    HPModuleCore = 0,
    HPModuleBase,
    HPModuleSpeech
};

#endif /* HaptikSharedConstants_h */
