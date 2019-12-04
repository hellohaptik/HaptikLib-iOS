---
title: Integration Guide
---

This Integration Guide contains chronological steps required to integrate the Haptik iOS SDK.

---

## Prerequisites

- Minimum Deployment Target: **iOS 9.0**
- Supported Device Orientation: **Portrait**

> You also need to have [git-lfs](https://git-lfs.github.com/) installed on your machine for running the SDK

---

## I. Installation

1. Add the following dependencies in `Podfile` -

   ```ruby
   pod 'HaptikLib'
   ```

   To make use of Voice Capabilities

   ```ruby
   pod 'HaptikLib/Speech'
   ```

2) Run `pod install`

---

## II. Required Permissions

HaptikLib requires some permissions and custom properties to function properly. Add the following snippets in your `Info.plist` file.

<details open>
   <summary> Haptik only supports <b>Portrait</b> orientation </summary>

```XML
<key>UISupportedInterfaceOrientations</key>
<array>
   <string>UIInterfaceOrientationPortrait</string>
</array>
```

</details>

<details open>
   <summary> <b>Privacy - Photo Library Usage Description</b> to enable a user to upload photos from the photos gallery in the chat flows </summary>

```XML
<key>NSPhotoLibraryUsageDescription</key>
<string>To enable usage & saving of photos</string>
<key>NSPhotoLibraryAddUsageDescription</key>
<string>To enable usage & saving of photos</string>
```

</details>

<details open>
   <summary> <b>Privacy - Camera Usage Description</b> to enable a user to upload photos from camera within chat flows </summary>
   
   ```XML
   <key>NSCameraUsageDescription</key>
   <string>To enable camera usage for uploading photos</string>
   ```
</details>

<details open>
   <summary> <b>Privacy - Contacts Usage Description</b> To access phone contacts</summary>
   
   ```XML
   <key>NSContactsUsageDescription</key>
   <string>With contacts access, we provide an easy way to give you app support</string>
   ```
</details>

If you already allow <b>Arbitrary Loads</b> then you can skip adding the exception domains given below.

<details open>
   <summary> Enter the following <b>exception domains</b> for HaptikLib to work properly: </summary>

```XML
<key>NSAppTransportSecurity</key>
<dict>
   <key>NSExceptionDomains</key>
   <dict>
      <key>haptik-staging.s3.amazonaws.com</key>
      <dict>
         <key>NSIncludesSubdomains</key>
         <true/>
         <key>NSThirdPartyExceptionAllowsInsecureHTTPLoads</key>
         <true/>
      </dict>
      <key>haptikapi.com</key>
      <dict>
         <key>NSIncludesSubdomains</key>
         <true/>
         <key>NSThirdPartyExceptionAllowsInsecureHTTPLoads</key>
         <true/>
      </dict>
      <key>haptikdev.s3.amazonaws.com</key>
      <dict>
         <key>NSIncludesSubdomains</key>
         <true/>
         <key>NSThirdPartyExceptionAllowsInsecureHTTPLoads</key>
         <true/>
      </dict>
      <key>staging.hellohaptik.com</key>
      <dict>
         <key>NSIncludesSubdomains</key>
         <true/>
         <key>NSThirdPartyExceptionAllowsInsecureHTTPLoads</key>
         <true/>
      </dict>
   </dict>
</dict>
```

</details>

---

## III. Initialization

1. The Haptik SDK should be initialized before it can perform any operations. _Initialization_ here implies providing appropriate **Client ID**, **Base URL** & **Run Environment** to Haptik SDK.

2. The following `key-value` pairs should be present in the Custom Dictionary `HaptikLib` -

   | Key            | Value                              |
   | -------------- | ---------------------------------- |
   | baseUrl        | INSERT_BASE_URL_HERE               |
   | clientID       | INSERT_CLIENT_ID_HERE              |
   | runEnvironment | INSERT_APPROPRIATE_RUN_ENVIRONMENT |

3. The Haptik SDK takes all the necessary things from app's `Info.plist` file automatically
4. Add these initialization keys substituted with their appropriate values in a custom dictionary named `HaptikLib`
5. On opening app's `Info.plist` in _Source Code_ format & add the required keys as illustrated below -

   ```XML
   <key>HaptikLib</key>
   <dict>
     <key>clientID</key>
     <string>INSERT_CLIENT_ID_HERE</string>
     <key>baseUrl</key>
     <string>INSERT_BASE_URL_HERE</string>
     <key>runEnvironment</key>
     <string>INSERT_APPROPRIATE_RUN_ENVIRONMENT</string>
   </dict>
   ```

   **Note:** The Base URL will be different for different `runEnvironment` as specified below -

   ```ObjC
   HaptikLibEnvProduction = 0,
   HaptikLibEnvStaging = 1,
   HaptikLibEnvDev = 2
   ```

---

## IV. AppDelegate Configurations

1. Import HaptikLib in your AppDelegate Class

   ```ObjC
   @import HaptikLib;
   ```

2. Haptik uses the _application_ instance and the _launchOptions_ dictionary internally. The `Haptik.h` class provides a method to pass the required parameters.

   ```ObjC
   - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

      ...

      [[Haptik sharedSDK] notifyApplication:application launchedWithOptions:launchOptions];

      return YES;
   }
   ```

3. Haptik can also be configured to send Push Notifications to the user. The client application needs to configure push notifications on their own end and have to pass the deviceToken which the application gets after requesting the user to send them Push Notifications.

   ```ObjC
   - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {

       ...

       [[Haptik sharedSDK] setDeviceToken:deviceToken];
   }
   ```

4. For Haptik to handle it's own notifications, you have to pass the required **notification response** that you get in the **notifications payload** and the instance of the `viewController` from where the notifications should be handled. It's also possible to determine whether notification payload is Haptik-specific or not.

> For iOS 9.x and below iOS 10.x

```ObjC
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {

   ...

   BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];

   if (canBeHandledByHaptik) {
      NSLog(@"do housekeeping");
   }

[[Haptik sharedSDK] didReceiveHaptikRemoteNotification:PASS_NOTIFICATION_DICTIONARY_HERE
                     controller:PASS_VIEWCONTROLLER_INSTANCE_HERE];
}
```

> For iOS 10.x and above

```ObjC
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response
   withCompletionHandler:(void(^)(void))completionHandler {

   ...

   BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:userInfo];

   if (canBeHandledByHaptik) {
NSLog(@"do housekeeping");
   }

   [[Haptik sharedSDK] didReceiveHaptikNotificationResponse:PASS_NOTIFICATION_RESPONSE_HERE
                     controller:PASS_VIEWCONTROLLER_INSTANCE_HERE];

   completionHandler();
}

```

---

## V. User Authentication

1. After successful Initialization & App Delegate Configuration, SDK can enable a user to Signup for using Haptik services
2. Haptik Signup is sub-divided in following 2 parts -

   - Collecting required parameters of user 
   - Passing over the collected parameters to Haptik

3. The public class `HPSignUpObject` is to be used for _collecting the required parameters_ as illustrated below -

   ```ObjC
   HPSignUpObject *signupObj = [HPSignUpObject buildWithAuthType:@"AUTH_TYPE_HERE" data:^(HPSignUpBuilder * _Nonnull builder) {

      builder.userFullName = INSERT_NAME_HERE;
      builder.viaName = INSERT_BUSINESS_VIA_NAME_HERE;
   }];
   ```
   >  `viaName` is the unique business name of the channel that you wish to open.

---

## VI. User Signup Flow

1. The `HPSignUpObject *signupObj` instance created in above step is now to be passed to SDK
2. This step involves a network request so to maintain state of the application & update a user about current progress, the SDK provides following API.

3. `[[Haptik sharedSDK] signUpWith:completion:]` takes a `HPSignUpObject` instance and _on completion handler_ that is passed the result of signUp attempt
4. The `UIViewController` instance returned on signup represents the _Conversation Screen_ for the _viaName_ in the passed `HPSignUpObject`. If `via_name` is incorrect or not passed this will be nil.
5. The completion block is invoked on `mainQueue`
6. Using `success` & `error` objects, any analytics / app state update / general housekeeping can be performed

   ```ObjC
   [[Haptik sharedSDK] signUpWith:signupObj
                        completion:^(BOOL success, __kindof UIViewController * _Nullable viewController, NSError * _Nullable error) {

       NSLog(@"Do housekeeping using success & error");

           if (success) {

               //redirect the user to a channel
               
               if (viewController) {
                  [self.navigationController pushViewController:viewController animated:YES];
               }
           }
            else {
               NSLog(@"User Signup Failed!");
            }
   }];
   ```

---

## VII. Existing Users Flow (Signed-up users)

1. If a user is already signed-up in Haptik SDK such a user should be directly presented the Channel screen
2. The SDK provides a BOOL attribute `isUserSignedUp` to verify whether the user is successfully signed up or not

- If YES, then the user should be presented the Conversation Screen
- If NO, then the user should be taken to Sign Up flows as mentioned above in Step V & VI

```ObjC
if ([[Haptik sharedSDK] isUserSignedUp]) {
    // perform analytics, state update, etc
   [[Haptik sharedSDK] launchChannelWith:@"INSERT_BUSINESS_VIA_NAME_HERE"
                                 message:@"INSERT_CUSTOM_MESSAGE_TEXT_HERE"
                              controller:visibleViewController];
}
else {
    // Continue with the SignUp flow here
}
```

---

## VIII. Share Functionality

Haptik provides inbuilt share functionality where user can share their client app with others via social media apps or any other medium.

You have to add a **Dictionary** inside the `HaptikLib` Info.plist dictionary which you added for credentials during the initialization.

The dictionary should be named `shareAndRate` and the following **key-value** should be present in it:

| Key                  | Value                    | Usage                                     |
| -------------------- | ------------------------ |-------------------------------------------|
| appStoreUrl          | INSERT_APP_STORE_URL     |The App Store link used for rating the app.|
| shareText            | INSERT_SHARE_TEXT        |This message will be used to share the app.|
| shareUrl             | INSERT_SHARE_URL         |This url will be added in the shareText.   |
| iTunesItemIdentifier | INSERT_ITUNES_IDENTIFIER |Itunes ID of your app used for user rating.|
|

 Inside the shareText wherever there will be %@ present, it will be replaced by the shareUrl.

<details open>
   <summary> <b> Example:</b> </summary>

```XML
<key>HaptikLib</key>
<dict>
   <key>clientID</key>
   <string>INSERT_CLIENT_ID_HERE</string>
   <key>baseUrl</key>
   <string>INSERT_BASE_URL_HERE</string>
   <key>runEnvironment</key>
   <string>INSERT_APPROPRIATE_RUN_ENVIRONMENT</string>

   ***

   <key>shareAndRate</key>
   <dict>
      <key>appStoreUrl</key>
      <string>INSERT_APP_STORE_URL</string>
      <key>shareText</key>
      <string>INSERT_SHARE_TEXT</string>
      <key>shareUrl</key>
      <string>INSERT_SHARE_URL</string>
      <key>iTunesItemIdentifier</key>
      <string>INSERT_ITUNES_IDENTIFIER</string>
   </dict>

   ***

</dict>
```
</details>

> If the values are not added then by default Haptik is shared with its custom text.

---

