---
title: Features
---

## SignOut

To Signout the current user from Haptik, use the following method on `[Haptik sharedSDK]`:

```ObjC
[[Haptik sharedSDK] signoutFromHaptik:^(BOOL success, NSError * _Nullable error) {

if (success) {

}
else {

}
}];
```

> **Note**: You have to set the device token again after the SignOut.

---

## Opening Conversation View
Once the user has been signed up, you also have the ability to open Conversation View for a specific channel directly. It needs to be Initialized with the unique business name of the channel that you wish to open Conversation for and an optional message text (can be `nil`) if you want to log any.

Example:

```ObjC
[[Haptik sharedSDK] launchChannelWith:@"INSERT_BUSINESS_VIA_NAME_HERE"
                              message:@"INSERT_CUSTOM_MESSAGE_TEXT_HERE"
                           controller:visibleViewController];
```

If you wish to push to the conversation view by yourself you can use the following API:

```ObjC
    NSError *error;
    UIViewController *haptikConversation = [[Haptik sharedSDK] getConversationForViaName:@"INSERT_BUSINESS_VIA_NAME_HERE"
                                                                                   error:&error];
    if (error) {
        // Handle Error case
        return;
    }

    [self.navigationController pushViewController:haptikConversation animated:YES];
```

- Check for selected [language](#localization) before pushing to a conversation screen.

---

## Unread Count

HaptikLib provides the `unreadCount` of the chat that the user has not read.

```ObjC
- (void)getUnreadCountFor:(NSString *)viaName
           WithCompletion:(void(^)(NSUInteger unreadCount, NSError * _Nullable error))completion;
```

You get the count(`NSUInteger`) in the `completion` block of the function. The completion is returned on the `mainQueue`. You can potentially use this count and add a Glyph Label on the Icon from where you are pushing the user inside **Haptik**.

Example:

```Objc
[[Haptik sharedSDK] getUnreadCountFor:@"INSERT_BUSINESS_VIA_NAME_HERE"
                       WithCompletion:^(NSUInteger unreadCount, NSError * _Nullable error) {

                        if (error) {
                            NSLog(@"%@", [error localizedDescription]);
                        }
                        else {

                            // Use the unread count here
                        }
    }];
```

---

## Localization

HaptikLib provides the option to change the language of the SDK.

HaptikLib uses the [ISO 639-1](https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes) format for languages.

The list of supported languages can be accessed from `HPLanguages`.

```ObjC
if ([HPLanguages containsObject:@"en"]) {
    //do your thing
}
```

Current selected language can be obtained from `HaptikConfigs.currentHaptikLocale` which will return a [ISO 639-1 code](https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes).
The default selected language will be English ("en").

You can change the current language of the SDK using the following method in `HaptikConfigs`

```ObjC
[HaptikConfigs setHaptikLocale:@"en" with:^(BOOL success) {

                                                if (success) {
                                                    //language is successfully set
                                                }
                                                else {
                                                    //revert back
                                                }
                                            }];
```

> Note: Changing Language triggers a network call, meaning the callback won't necessarily be called immediately. Plan your language change calls accordingly.

Also users can change the language from conversation screen. So make sure you check `HaptikConfigs.currentHaptikLocale`

---

