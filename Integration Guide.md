# INTEGRATION GUIDE

This Integration Guide contains chronological steps required to integrate the Haptik iOS SDK.

---


### Prerequisites

Minimum Deployment Target: **iOS 9.0**

Supported Device Orientation: **Portrait**

---


### I. Installation

1. Add the following dependencies in `Podfile` -
	```
	pod 'HaptikLib'
	pod 'NativeSSOLogin', :git=>'https://bitbucket.org/agi_sso/nativessologin.git', :tag => '1.0.12'
	```

2. Run `pod install`

---

### II. Required Permissions

HaptikLib requires some permissions and custom properties to function.
Add the following snippets in your `info.plist` file -

1. Allow arbitrary network loads to be requested

	```
	<key>NSAppTransportSecurity</key>
	  <dict>
	       <key>NSAllowsArbitraryLoads</key>
	       <true/>
	  </dict>
	```

2. Haptik only supports Portrait orientation

	```
	<key>UISupportedInterfaceOrientations</key>
	<array>
	<string>UIInterfaceOrientationPortrait</string>
	</array>
	```

3. Privacy - Photo Library Usage Description to enable a user to upload photos from the photos gallery in the chat flows

	```
	<key>NSPhotoLibraryUsageDescription</key>
	<string>To enable usage & saving of photos</string
	<key>NSPhotoLibraryAddUsageDescription</key>
	<string>To enable usage & saving of photos</string>
	```

4. Privacy - Camera Usage Description to enable a user to upload photos from camera within chat flows

	```
	<key>NSCameraUsageDescription</key>
	<string>To enable camera usage for uploading photos</string>
	```

---


### III. Initialization

1. The Haptik SDK should be initialized before it can perform any operations
2. _Initialization_ here implies providing appropriate **API Key**, **Client ID**, **Base URL** & **Run Environment** to Haptik SDK
3. The following `key-value` pairs should be present in the Custom Dictionary `HaptikLib` -

	| Key 			| Value			|
	|-----------------------|-----------------------|
	|apiKey			|INSERT_API_KEY_HERE|
	|baseUrl		|INSERT_BASE_URL_HERE|
	|clientID		|INSERT_CLIENT_ID_HERE|
	|runEnvironment		|INSERT_APPROPRIATE_RUN_ENVIRONMENT|

4. The Haptik SDK takes all the necessary things from app's `Info.plist` file automatically
5. Add these initialization keys substituted with their appropriate values in a custom dictionary named `HaptikLib`
6. On opening app's `Info.plist` in _Source Code_ format & add the required keys as illustrated below -

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

	**Note:** The Base URL will be different for different `runEnvironment` as specified below -

	```
	HaptikLibEnvProduction = 0,
	HaptikLibEnvStaging = 1,
	HaptikLibEnvDev = 2
	```
---


### IV. AppDelegate Configurations

1. Import HaptikLib in your AppDelegate Class
	```
	@import HaptikLib;
	```

2. Haptik uses the *application* instance and the *launchOptions* dictionary internally. The `Haptik.h` class provides a method to pass the required parameters.

	```
	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

	   ...

	   [[Haptik sharedSDK] notifyApplication:application launchedWithOptions:launchOptions];

	   return YES;
	}
	```

3. Haptik internally also opens urls which the client needs to return it true.


    ```
    (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {

      ...

      BOOL isRedirectHandledByHaptik = [[Haptik sharedSDK] isRedirectHandled:url options:options];

      return isRedirectHandledByHaptik;
    }
    ```

4. Haptik can also be configured to send Push Notifications to the user. The client application needs to configure push notifications on their own end and have to pass the deviceToken which the application gets after requesting the user to send them Push Notifications.

	```
	- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {

	    ...

	    [[Haptik sharedSDK] setDeviceToken:deviceToken];
	}
	```

5. For Haptik to handle it's own notifications, you have to pass the **notification dictionary** that you get in the **notifications payload** and the instance of the `viewController` from where the notifications should be handled. It's also possible to determine whether notification payload is Haptik-specific or not.

	```
	- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {

	     ...

	     BOOL canBeHandledByHaptik = [[Haptik sharedSDK] canHandleNotificationWithUserInfo:response.notification.request.content.userInfo];

	     if (canBeHandledByHaptik) {
	     	...
		NSLog(@"do housekeeping");
		[[Haptik sharedSDK] handleNotificationWithUserInfo:PASS_NOTIFICATION_DICTIONARY_HERE controller:PASS_VIEWCONTROLLER_INSTANCE_HERE];
	     }
	}
	```

---


### V. User Authentication

1. After successful Initialization & App Delegate Configuration, SDK can enable a user to Signup for using Haptik services
2. Haptik Signup is sub-divided in following 2 parts -
	- Collecting required parameters of user according to Authentication(Signup) Type: _Basic(Guest)_ or _OTP Verified_ user
	- Passing over the collected parameters to Haptik

3. The public class `HPSignUpObject` is to be used for _collecting the required parameters_ as illustrated below -

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

#### Authentication Types -

A. **Basic Authentication**
1. Basic Authentication is a Guest signup that does not require any verification `auth_type = @"basic"`
2. This is ideal for informational chatbots or when user verification is handled by a Third Party Service
3. The `Name` parameter is _required_ while signing up as Basic type
	```
	HPSignUpObject *signupObj = [HPSignUpObject buildWithAuthType:@"basic" data:^(HPSignUpBuilder * _Nonnull builder) {

		builder.userFullName = @"John Appleseed";
	}];
	```

B. **OTP Authentication**

1. An user’s mobile number OTP verification can be done by Haptik. Contact us for enabling server component for this.
2. The following parameters are required -
	- OTP Verified Mobile Number
	- Token/TicketId for OTP verification
	- User City
	- User Email Address

	**NOTE:** User City _must_ be one of following string types -
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

	OR

	[@"Other"]
	```
---


### VI. User Signup Flow

1. The `HPSignUpObject *signupObj` instance created in above step is now to be passed to SDK
2. This step involves a network request so to maintain state of the application & update a user about current progress, the SDK provides following 2 APIs for flexibility -

A. **Asynchronous (without Loading Screen)**

1. `[[Haptik sharedSDK] signUpWith: completion:]` takes a `HPSignUpObject` instance and _on completion_ returns a `UIViewController` instance expected to be added on app's navigation stack
2. The `UIViewController` instance returned on succesful signup represents the root _Inbox Screen_ of SDK
3. The completion block is invoked on `mainQueue`
4. Using `success` & `error` objects, any analytics / app state update / general housekeeping can be performed

	```
	[[Haptik sharedSDK] signUpWith:signupObj completion:^(BOOL success, UIViewController * _Nullable initialVC, NSError * _Nullable error) {

		NSLog(@"Do housekeeping using success & error");

	        if (success) {
	            [self.navigationController pushViewController:initialVC animated:YES];
	        }
		else {
		    NSLog(@"User Signup Failed!");
		}
	}];
	```

B. **Synchronous (with Customisable Loading Screen)**

1. `[[Haptik sharedSDK] signUpWithLoadingScreenFor: completion:]` takes a `HPSignUpObject` instance and _immediately returns_ `UIViewController` instance expected to be added on app's navigation stack
2. The `UIViewController` instance returned immediately represents the root _Inbox Screen_ of SDK
3. The returned `UIViewController` instance has a built in _Customisable Loading Screen_ shown while signup network request is in progress
4. The root _Inbox Screen_ of SDK is automatically presented on succesful signup
5. String attributes of `loadingTitleText` & `loadingSubtitleText` can be set to present a custom message to user while signup network request is in progess
6. If not set, the default string values of the above mentioned attributes is as follows -
	- `loadingTitleText`: @"Behind every successful person is an Assistant!"
	- `loadingSubtitleText`: @"Coming right up…"
7. These attributes should be set before `[[Haptik sharedSDK] signUpWithLoadingScreenFor: completion:]` function is invoked
	```
	[Haptik sharedSDK].loadingTitleText = @"My custom title text for user";
    [Haptik sharedSDK].loadingSubtitleText = @"My custom subtitle text for user";

	UIViewController * __block initialVC = [[Haptik sharedSDK] signUpWithLoadingScreenFor:signupObj completion:^(BOOL success, NSError * _Nullable error) {

												NSLog(@"Do housekeeping using success & error");

												if (success) {
													NSLog(@"User Signup Success! Can do Analytics, state update, etc here");
												}
												else {
													NSLog(@"User Signup Failed!");
												}
										    }];

	[self.navigationController pushViewController:initialVC animated:YES];
	```

---

### VII. Existing Users Flow (Signed-up users)

1. If a user is already signed-up in Haptik SDK such a user should be directly presented SDK's root _Inbox Screen_
2. The SDK provides a BOOL attribute `isUserSignedUp` to verify whether the user is successfully signed up or not
 - If YES, then the user should be presented the root _Inbox Screen_ using the `getInitialVC` function
 - If NO, then the user should be taken to Sign Up flows as mentioned above in Step V & VI
3. The `getInitialVC` function returns nil if a user is not signed-up in Haptik SDK

	```
	if ([[Haptik sharedSDK] isUserSignedUp]) {

		// perform analytics, state update, etc
		UIViewController *haptikInboxScreen = [[Haptik sharedSDK] getInitialVC];
		[self.navigationController pushViewController:haptikInboxScreen animated:YES];
    }
    else {
		// Continue with the SignUp flow here
    }
	```

---


## VIII. Share Functionality

Haptik provides inbuilt share functionality where user can share the client app with others via social media apps or any other medium.

- When user shares something from inside the HaptikSDK, a **custom content message** gets shared. Client can **override this message** with their own custom content along with their `deeplink` URL.

- Haptik also provides an inbuilt feature where it can take the users **directly to the client application’s App Store Page** to rate the application.

The option to set these values is given in the `Info.plist` file of the application.

> If the values are not added then by default Haptik is shared with its custom text.

You have add a **Dictionary** inside the `HaptikLib` dictionary which you added for credentials during the initialization. Note that the keys should match the provided keys otherwise default behaviour will be implemented.

The dictionary should be named `shareAndRate` and the following **key-value** should be present in it:

| Key 									| Value							 |
|-----------------------|--------------------|
|appStoreUrl						|INSERT_APP_STORE_URL|
|shareText							|INSERT_SHARE_TEXT|
|shareUrl								|INSERT_SHARE_URL|

##### Example:

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
