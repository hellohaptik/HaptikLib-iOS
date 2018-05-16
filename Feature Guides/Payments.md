## Step 1 (Permissions Needed)

* Privacy - Contacts Usage Description. For user to select phone numbers from it's contacts list (to make a recharge, etc), this permission is required. Add the following snippet:

```
<key>NSContactsUsageDescription</key>
	<string>INSERT_YOUR_DESCRIPTION_HERE</string>
```

* For making work payments through AmazonPay, you need to add a Custom URL Type in your `Info.plist` file. Add the following snippet:

```
<key>CFBundleURLTypes</key>
 <array>
     <dict>
        <key>CFBundleURLName</key>
        <string>com.amazon.pwain</string>
        <key>CFBundleURLSchemes</key>
        <array>
            <string>amzn.$(PRODUCT_BUNDLE_IDENTIFIER)</string>
        </array>
      </dict>
  </array>
```

## Step 2 (Wallet Information Screen)

HaptikLib has an inbuilt wallet information screen to which you can push the user and has two tabs:

1. To View Wallet Balance

2. To see wallet transactions history

###### Is Haptik Wallet Created?

Haptik only creates `wallet` for the users which are verified(phone number of the user must verified). If the user is not verified and the `Haptik Wallet VC` is pushed, then the user is automatically taken to the **user verification flow**.

HapikLib give a helper function which tells if the `Wallet` is created for the user or not. You can use the below function to check:

```
- (BOOL)isHaptikWalletCreated;
```

###### How to take the user to the wallet scene?

Haptik class provides custom method to route to this screen:

```
- (void)getHaptikWalletViewController:(BOOL)defaultsToHistory
                 shareAndEarnDelegate:(nullable id <HPShareAndEarnDelegate>)delegate
                           controller:(__kindof UIViewController *__weak)controller
                           completion:(void(^)(BOOL success, __kindof UIViewController *_Nullable haptikWalletVC))completion;
```

Example:

```
[[Haptik sharedSDK] getHaptikWalletViewController:NO
                                  shareAndEarnDelegate:nil
                                            controller:controller
                                            completion:^(BOOL success, __kindof UIViewController * _Nullable haptikWalletVC) {
            if (success) {
                [controller.navigationController pushViewController:haptikWalletVC animated:YES];
            }
        }];
```

**Discussion**

> The user should be a verified user (phone number of the user is verified) in order to see & use the wallet scene. If the user is not verified and this scene is pushed, HaptikLib takes the user through the verification flow. You don't have to do anything else for it. You'll just get the `Haptik Wallet VC` in the completion.

- The `param`: `defaultsToHistory` indicates which tab should selected by default when the scene is pushed.

- The `param`: `shareAndEarnDelegate` should be passed nil as referral flow is not yet supported for clients other than `Haptik` itself.

- The `param`: `controller` requires the current controller from where this scene is to be pushed potentially. This controller is required for `HaptikLib` in order to handle the user verification flow.

- In the `completion`, you get two parameters:

	- `success`: Indicates whether the user is verified or not.

	- `haptikWalletVC`: You'll get the instance of the `Haptik Wallet VC` only if the user is verified, which you'll know from the `success` param.


###### Can I get the current wallet balance of the user?

Yes, you definitely can. HaptikLib provides another helper function for that, mentioned below:

```
- (NSString *)getHaptikWalletBalance;
```

Returns `String` value of User's **Haptik Wallet Balance**. Will return `nil` if:

- User's wallet has not been created yet.
- Haptik Wallet Servers are currently down.


###### How will I know if the user's wallet balance is updated?

Everytime the user's wallet balance is updated, HaptikLib fires a Notification named `HPWalletBalanceUpdated` for you to observe. You'll get the updated wallet balance of the user in the same function mentioned above.


---

## Step 3 (Transaction History Screen)

HaptikLib has an inbuilt transaction history screen to which you can push the user.

Haptik class provides custom method to route to this screen:

```
- (void)getTransactionHistoryFor:(__kindof UIViewController *__weak)controller
                      completion:(void(^)(BOOL success, __kindof UIViewController *_Nullable transactionsVC))completion;
```

Example:

```
[[Haptik sharedSDK] getTransactionHistoryFor:controller
                                       completion:^(BOOL success, __kindof UIViewController * _Nullable transactionsVC) {

            if (success) {
                [controller.navigationController pushViewController:transactionsVC animated:YES];
            }
        }];
```

> Just like the case with the `Haptik Wallet Screen`, the user should be a verified user (phone number of the user is verified) in order to see & use the `Transaction History` scene. If the user is not verified and this scene is pushed, HaptikLib takes the user through the verification flow. You don't have to do anything else for it. You'll just get the `Transaction History VC` in the completion.

**Discussion**

- The `param`: `controller` requires the current controller from where this scene is to be pushed potentially. This controller is required for `HaptikLib` in order to handle the user verification flow.

- In the `completion`, you get two parameters:

	- `success`: Indicates whether the user is verified or not.

	- `transactionsVC`: You'll get the instance of the `Transaction History VC` only if the user is verified, which you'll know from the `success` param.


---
