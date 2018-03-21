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
    }];
```

> To find out where all the different properties are used like, where all `brandColor` is used, etc, please refer to the **Design Guidelines Document for HaptikLib**.

---
