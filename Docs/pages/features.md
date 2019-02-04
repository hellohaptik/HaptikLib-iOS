---
title: Features
---

## SignOut

To Signout the current user from Haptik, use the following method on `[Haptik sharedSDK]`:

```
[[Haptik sharedSDK] signoutFromHaptik:^(BOOL success, NSError * _Nullable error) {

if (success) {

}
else {

}
}];
```

> **Note**: You have to set the device token again after the SignOut.

---

## InteractivePopGesture

This BOOL controls the functionality of the `EdgePanGestureRecognizer` feature of UINavigationController that allows to set the slide to go back functionality for Haptik Screens. By default the value will be true.

```
[Haptik sharedSDK].useInteractivePopGesture = YES;
```

---

## Opening Conversation View Directly

Once the user has been signed up, you also have the ability to open Conversation View for a specific channel directly. It needs to be Initialized with the unique business name of the channel that you wish to open Conversation for and an optional message text (can be `nil`) if you want to log any.

Example:

```
[[Haptik sharedSDK] launchChannelWith:@"INSERT_BUSINESS_VIA_NAME_HERE"
                                  message:@"INSERT_CUSTOM_MESSAGE_TEXT_HERE"
                               controller:visibleViewController];
```

---

## Unread Count

HaptikLib provides the total `unreadCount` of the chats that the user has not read.

```
- (void)getUnreadCountWithCompletion:(void(^)(NSUInteger unreadCount))completion;
```

You get the count(`NSUInteger`) in the `completion` block of the function. The completion is returned on the `mainQueue`. You can potentially use this count and add a Glyph Label on the Icon from where you are pushing the user inside **Haptik**.

Example:

```
[[Haptik sharedSDK] getUnreadCountWithCompletion:^(NSUInteger unreadCount) {

        // Use the unread count here
    }];
```

---

## Offers Screen

HaptikLib has another interesting thing for the users, that is an **Offers Screen**. The user can see all the **currently running offers on Haptik** on this Screen. You just have to push the user to this screen using the method mentioned below:

```
- (__kindof UIViewController *_Nullable)getOffersViewContoller;
```

Example:

```
[controller.navigationController pushViewController:[[Haptik sharedSDK] getOffersViewContoller] animated:YES];
```

You'll the the `Offers VC` by calling the above method and then push the user to it. That's it. HaptikLib is handle everything else.

**Offers Count**

You can also get the count of the current offers running on Haptik through the helper function mentioned below:

```
- (NSUInteger)getOffersCount;
```

> Note: The offers count will be available through this function only after the user has been pushed to this screen once in the lifetime.

---
