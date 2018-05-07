# HAPTIK iOS SDK
INTEGRATION GUIDE (v0.3.0)

### Authors

[Simranjot Singh](mailto:simranjyot@haptik.co)
[Yogesh Singh](mailto:yogesh@haptik.ai)

## Introduction

Say goodbye to App Fatigue. Instantly enable 100+ chatbots across various daily tasks.
The mobile apps industry is about a decade old but publishers are still trying to figure out hacks to improve user retention. App fatigue is not just a theory any more: 60% of apps are uninstalled within the first week. The Haptik Assistant SDK enables a layer of daily use chatbots in any mobile app. Instantly provide a lot more reasons for users to keep using your app. You can also monetize through transactions and the Haptik ads platform.


This documentation contains the information that will be required to integrate the Haptik iOS SDK end to end. The document is divided in a progressing way as what is needed to be done step by step so as to integrate it successfully.

---


## Prerequisites

Minimum Deployment Target: **iOS 9.0**

Supported Device Orientation: **Portrait**

---


## Step 1 (Installation)

Add  the following dependencies to your `Podfile` and run `pod install`:

- **'HaptikLib'**
- **'NativeSSOLogin', :git=>'https://bitbucket.org/agi_sso/nativessologin.git', :tag => '1.0.12'**


---


## Step 2 (Required Permissions)

HaptikLib requires some permissions and custom properties to function. Add the following snippets in your `info.plist` file.

* Allow arbitrary network loads to be requested. Add the following snippet in your `Info.plist` file:

```
<key>NSAppTransportSecurity</key>
  <dict>
       <key>NSAllowsArbitraryLoads</key>
       <true/>
  </dict>
```

* HaptikLib only supports UIInterfaceOrientationPortrait. Add the following snippet in your `Info.plist` file:

```
<key>UISupportedInterfaceOrientations</key>
	<array>
		<string>UIInterfaceOrientationPortrait</string>
	</array>
```

* Privacy - Photo Library Usage Description. The user can upload photos from the photos gallery in the chat flows, hence this permission is required. Add the following snippet:

```
<key>NSPhotoLibraryUsageDescription</key>
	<string>INSERT_YOUR_DESCRIPTION_HERE</string
```

* Privacy - Photo Library Additions Usage Description. The user can upload photos from the photos gallery in the chat flows, hence this permission is required. A user can Add the following snippet:

```
<key>NSPhotoLibraryAddUsageDescription</key>
	<string>INSERT_YOUR_DESCRIPTION_HERE</string>
```

* Privacy - Camera Usage Description. The user can upload photos from directly from the camera in the chat flows, hence this permission is required. Add the following snippet:

```
<key>NSCameraUsageDescription</key>
	<string>INSERT_YOUR_DESCRIPTION_HERE</string>
```

---


## Step 3 (Initialization)

The HaptikLib SDK should be initialized before it can perform any operations. *Initialization* here implies providing appropriate **API Key**, **Client ID**, **Base URL** & **Run Environment** to HaptikLib SDK. These would be sent over by Haptik via appropriate communication channels. Once above mentioned keys are made available perform the following things:

> Note: The HaptikLib SDK takes all the necessary things from your *Info.plist* file automatically. So you need to add all the required initialization and other required keys along with their appropriate values in a dictionary under a custom key called `HaptikLib` only once.

The following `key-value` pairs should be present in a Custom Dictionary `HaptikLib`:

| Key 									| Value							 |
|-----------------------|--------------------|
|apiKey								|INSERT_API_KEY_HERE|
|baseUrl							|INSERT_BASE_URL_HERE|
|clientID							|INSERT_CLIENT_ID_HERE|
|runEnvironment				|INSERT_APPROPRIATE_RUN_ENVIRONMENT|

Open your app’s *.plist* file in *Source Code* format & add the required keys as illustrated in snippet below.

```
<key>HaptikLib</key>
<dict>
  <key>apiKey</key>
  <string>INSERT_API_KEY_HERE</string>
  <key>baseUrl</key>
  <string>INSERT_BASE_URL_HERE</string>
  <key>clientID</key>
  <string>INSERT_CLIENT_ID_HERE</string>
  <key>runEnvironment</key>
  <string>INSERT_APPROPRIATE_RUN_ENVIRONMENT</string>
</dict>
```

> Note: You can set runEnvironment with the following options. The Base URL will be different for different runenvironments.

```
HaptikLibEnvProduction = 0,
HaptikLibEnvStaging = 1,
HaptikLibEnvDev = 2
```

---


## Step 4 (AppDelegate Configurations)

Import HaptikLib in your AppDelegate Class either by writing `#import <HaptikLib/Haptik.h>` or `@import HaptikLib;`

- HaptikLib uses the *application* instance and the *launchOptions* dictionary internally. The `Haptik.h` class provides a method to pass the required parameters.

    Example:

    ```
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    [[Haptik sharedSDK] notifyApplication:application launchedWithOptions:launchOptions];    

    	return YES;
    }
    ```

- HaptikLib internally also opens urls which the client needs to return it true.

    Example:

    ```
    (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {

     return [[Haptik sharedSDK] isRedirectHandled:url options:options];
    }
    ```

- HaptikLib can also be configured to send Push Notifications to the user. The client application needs to configure push notifications on their own end and have to pass the deviceToken which the application gets after requesting the user to send them Push Notifications.

    Example:

    ```
    - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {

    	[[Haptik sharedSDK] setDeviceToken:deviceToken];
    }
    ```

- For HaptikLib to handle it's own notifications, you have to pass the **notification dictionary** that you get in the **notifications payload** and the instance of the `viewController` from where the notifications should be handled. You can also check if the notification belongs to HaptikLib or not.
	Example:

	```
	- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {

     BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:response.notification.request.content.userInfo];

     if (canBeHandledByHaptik) {
         NSLog(@"do housekeeping");
         [[Haptik sharedSDK] handleNotificationWithUserInfo:PASS_NOTIFICATION_DICTIONARY_HERE controller:PASS_VIEWCONTROLLER_INSTANCE_HERE;
       }
	}
	```

	> You should add this function in all the different Notification Delegate methods in which you get the Notification Payload.

---


## Step 5 (User Authentication)

After successfully configuring & setting up HaptikLib, you'll be able to proceed to the user signup flow. Signup includes mainly two steps. First, collecting the required parameters of the end user according to the type they are signing up (`Guest user` or `verified user`) and second passing the collected parameters to HaptikLib.

###### Signup Types

HaptikLib gives a public class `HPSignUpObject` which you can use to collect the required parameters. Each auth flows require a different set of parameters passed to HPSignUpObject. Contact Haptik for knowing more about your `Auth-Type` & `Auth-ID`.

This class follows the builder pattern. Here's an example of how to make use of it:

```
HPSignUpObject *signupObj = [HPSignUpObject buildWithAuthType:@"AUTH_TYPE_HERE" data:^(HPSignUpBuilder * _Nonnull builder) {

        builder.userFullName = INSERT_NAME_HERE;
        builder.userPhoneNumber = INSERT_PHONE_NUMBER_HERE;
        builder.userEmail = INSERT_EMAIL_HERE;
        builder.userCity = INSERT_CITY_HERE;
        builder.authToken = INSERT_AUTH_TOKEN_HERE;
        builder.authID = INSERT_AUTH_ID_HERE;
    }];   
```

- **Basic Auth**

  **Auth_Type = @"basic";**

	Basic Authentication is a guest form of signup that does not require any sort of server-server/ 3rd party verification. This is ideal for chat bots that are either informational in nature or where user identity is handled by a 3rd party provider.

	The following parameter is required while signing up with **BASIC** authType:

	- *Optional*: Name


  > Although name is optional, but it is recommended to provide user's name as it does help in customising user experience.


- **OTP**

  **Auth_Type = @"otp";**

	An end user’s mobile number OTP verification can be done by Haptik. Please contact us for utilising this feature.

  The following parameter is compulsory while signing up with **OTP** authType:

  - *Mandatory*: OTP Verified Mobile Number
  - *Mandatory*: Token/TicketId for OTP verification (for 3-way handshake, creation of Wallet)
  - *Optional*: Resident City
	- *Optional*: Email (unverified is OK)


> **NOTE** that city name **MUST** be either one of the cities mentioned on Haptik SDK or provide "Other" as a String.

**City Appendix**:
```
[@"Mumbai", @"Bombay"]

[@"New Delhi", @"Delhi"]

[@"Bengaluru", @"Bangalore", @"Bengaluru South"]

[@"Chennai", @"Madras"]

[@"Pune", @"Poona"]

[@"Hyderabad", @"Secunderabad"]

[@"Kolkata", @"Calcutta"]

[@"Ahmedabad", @"Ahmadabad"]

[@"Thane", @"Mira Bhayandar", @"Mira Bhayander"]

[@"Navi Mumbai"]

[@"Gurugram", @"Gurgaon"]

[@"Noida", @"Greater Noida"]
```

---


## Step 6 (User Signup Flow)

To continue from the User Authentication, the signUp object is now passed to Haptik for signing up the user. Signing up the user is an API call and can take up some time. HaptikLib provides two different ways for that, one with a customised loading screen and other without it.

###### Type I  (Without Loading Screen)

HaptikLib defines a method that takes up the `HPSignUpObject` and returns the a `UIViewController` instance for you to push in the completion after the user has successfully signed up. The completion is returned on `mainQueue` by default.

Here an example:

```
[[Haptik sharedSDK] signUpWith:signupObj completion:^(BOOL success, UIViewController * _Nullable initialVC, NSError * _Nullable error) {

        if (success) {
            [self.navigationController pushViewController:initialVC animated:YES];
        }
    }];
```

###### Type II (With Loading Screen)

This method also takes the same parameters just as the above method takes. The key difference is that the function returns a `UIViewController` instance to push immediately irrespectively if the API call is still in progress. The returned view controller itself takes up the responsibility of showing the customised loading screen and the switching back to the desired `Inbox View`.

Here an example:

```
UIViewController * __block initialVC = [[Haptik sharedSDK] signUpWithLoadingScreenFor:signupObj completion:^(BOOL success, NSError * _Nullable error) {

        if (success) {                        
        }
        else {            
        }
    }];    

    [self.navigationController pushViewController:initialVC animated:YES];
```

This viewController takes custom text attributes individually to display the titles and subtitles on the Loading Screen. `Haptik.h` declares two properties named:

- loadingTitleText:

	- **Default text**: @"Behind every successful person is an Assistant!"


- loadingSubtitleText:

	- **Default text**: @"Coming right up…"

You can set these properties before pushing the viewController and set the `title` & `subtitle` text on the loading screen, otherwise default text will be set. It is highly recommended to show this viewController while user is signing up on Haptik SDK to make a smooth user experience.

---


## Step 7 (Existing Users flow)

You need to handle the flow where the user has already signed up and you want to directly take the user to Haptik's `Inbox Screen`. HaptikLib provides a function named `isUserSignedUp` that returns a `BOOL` value for the same. If `YES` you can get the desired `viewController` from the method `getInitialVC` and push the user directly. The function will return `nil` if the user hasn't been signed up.

Example:

```
if ([[Haptik sharedSDK] isUserSignedUp]) {

        [self.navigationController pushViewController:[[Haptik sharedSDK] getInitialVC] animated:YES];
    }
    else {

        // Continue with the SignUp flow here
    }
```

---


## Step 8 (Share Functionality)

HaptikLib provides **inbuilt share functionality** where user can share the client app with others via social media apps or any other medium.

- When user shares something from inside the HaptikSDK, a **custom content message** gets shared. Client can **override this message** with their own custom content along with their `deeplink` URL.

- HaptikLib also provides an inbuilt feature where it can take the users **directly to the client application’s App Store Page** to rate the application.

The option to set these values is given in the `Info.plist` file of the application.

> If the values are not added then by default Haptik is shared with its custom text.

You have add a **Dictionary** inside the `HaptikLib` dictionary which you added for credentials during the initialization. Note that the keys should match the provided keys otherwise default behaviour will be implemented.

The dictionary should be named `shareAndRate` and the following **key-value** should be present in it:

| Key 									| Value							 |
|-----------------------|--------------------|
|appStoreUrl						|INSERT_APP_STORE_URL|
|shareText							|INSERT_SHARE_TEXT|
|shareUrl								|INSERT_SHARE_URL|

Example:

```
<key>HaptikLib</key>
	<dict>		
		<key>apiKey</key>
		<string>INSERT_API_KEY_HERE</string>
		<key>baseUrl</key>
		<string>INSERT_BASE_URL_HERE</string>
		<key>clientID</key>
		<string>INSERT_CLIENT_ID_HERE</string>
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
		</dict>

		***

	</dict>
```

> Inside the shareText wherever there will be %@ present, it will be replaced by the shareUrl.


---
