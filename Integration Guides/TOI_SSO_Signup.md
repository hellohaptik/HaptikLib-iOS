## **TOI_SSO**

**Auth_Type = @"toi_sso";**

In `TOI_SSO` authentication type user’s phone number will be validated from the Haptik Backend via a client API for additional security before Haptik account and wallet creation.

The following parameters are required while signing up with **TOI_SSO** authType on top of what is required for **BASIC** authType:

- *Mandatory*: OTP Verified Mobile Number
- *Mandatory*: Token/TicketId for OTP verification (for 3-way handshake, creation of Wallet)
- *Optional*: Resident City


## Signup with SSO

If you are using `SSO` for your signup process, then HaptikLib provides a different method all together mentioned below:

```
- (__kindof UIViewController *_Nullable)signUpUserWithSSO:(void (^)(BOOL success, NSError * _Nullable error))completion;
```

You don't have to pass any data for signing up in this method. This function will automatically determine if the user is signed in on SSO then it'll signup the user directly with the SSO Credentials otherwise with `Basic` Auth Type.

Example:

```
UIViewController *initialVC = [[Haptik sharedSDK] signUpUserWithSSO:^(BOOL success, NSError * _Nullable error) {

     if (success) {
         // do housekeeping
     }
     else {
         UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Oops!"
         message:error.localizedDescription
         preferredStyle:UIAlertControllerStyleAlert];

         UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:nil];
         [alert addAction:action];
         [self presentViewController:alert animated:YES completion:nil];
     }
 }];

 [self.navigationController pushViewController:initialVC animated:YES];
```
