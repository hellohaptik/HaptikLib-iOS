---
title: Analytics
---

## HaptikLib Analytics

HaptikLib is geared up with **analytics** internally and also _provides the functionality of giving callbacks for every event tracking_. The `HPAnalyticsServiceDelegate` **protocol** gives an optional method (_see example below_) which is called if you confirm to the protocol.

**HPConfiguration** class exposes a property named `analyticsCallbackObject` of type `HPAnalyticsServiceDelegate` which the application needs to set with the object that will confirm to the protocol.

Example:

```ObjC
@interface ViewController () < HPAnalyticsServiceDelegate >

@implementation ViewController

- (void)viewDidLoad {

    [HPConfiguration shared].analyticsCallbackObject = self;
}

- (void)eventTracked:(NSString *)eventName forParams:(NSDictionary *)params {

    // Callback for every event recorded
}

@end
```

---

## CleverTap Setup

HaptikLib also comes with CleverTap inbuilt 🙌🏻. You just have to enter the CleverTap Credentials provided to you in the `HapikLib` dictionary which you added for the credentials during the initialization.

A dictionary with the name `CleverTap` is to be added in `HaptikLib`. The dictionary will have the following two **key-value** pairs:

| Key                | Value                        |
| ------------------ | ---------------------------- |
| CleverTapAccountID | INSERT_CLEVER_TAP_ACCOUNT_ID |
| CleverTapToken     | INSERT_CLEVER_TAP_TOKEN      |

Example:

```XML
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

        <key>CleverTap</key>
        <dict>
            <key>CleverTapAccountID</key>
            <string>INSERT_CLEVER_TAP_ACCOUNT_ID</string>
            <key>CleverTapToken</key>
            <string>INSERT_CLEVER_TAP_TOKEN</string>
        </dict>

        ***

</dict>
```

---

