---
title: Theming
---

## HaptikLib Theme Configurations

You can refer the Design Guidelines Document for HaptikLib to know what all theming it supports. To set the specific style guide HaptikLib gives another Public Class `HPThemeService` which also follows the builder pattern just like you did with `HPSignUpObject`.

You have to set the instance of `HPThemeService` to the `themeConfig` property of Haptik Class to see its effects.

Example:

```
[Haptik sharedSDK].themeConfig = [HPThemeService buildWithData:^(HPThemeServiceBuilder * _Nullable builder) {

        builder.brandColor =                // UIColor object here
        builder.businessChatText =          // UIColor object here
        builder.businessChatBackground =    // UIColor object here
        builder.messageTimeStamp =          // UIColor object here

        builder.lightFont =                 // Light font name here
        builder.regularFont =               // Regular font name here
        builder.mediumFont =                // Medium font name here

        builder.boldFont =                  // Bold font name here
        builder.semiBoldFont =              // Semi Bold font name here
        builder.italicFont =                // Italic font name here
    }];
```

If you don't provide custom colors to HPThemeService then HaptikLib will use the default colors.

It's mandatory to provide all the font's to HPThemeService. Haptik provides it's custom font files that you have to add in your project and
register them in your info.plist file. HaptikLib will then automatically use them even if you don't pass the names in the builder.

If you wish to use your own font, pass all the required fonts in the builder, else the SDK will give an assert and exit.

> To find out where all the different properties are used like, where all `brandColor` is used, etc, please refer to the **Design Guidelines Document for HaptikLib**.

---

## NavigationBar Theme Configurations

HaptikLib does not control the Navigation Controller (hence the navigation bar), but the client does. HaptikLib only gives an instance of a `ViewController` that the client application pushes on their navigation stack. To configure that navigation bar of that navigationController (modify `tint color` and `barTintColor` of navigation bar of the SDK View Controllers), use the following helper method:

```
[[Haptik sharedSDK] configureNavigationBarWithTintColor:[UIColor redColor]
                                            barTintColor:[UIColor whiteColor]
                                         makeTranslucent:YES
                                 forNavigationController:navController];
```

The params `tintColor` & `barTintColor` are `nullable`, i.e. you can pass `nil` for the respective param which you want to set to default (don't want to set).

---
