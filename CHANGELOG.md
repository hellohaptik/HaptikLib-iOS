#  CHANGELOG

This project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [0.5.0] - (07/05/18) - Khamoshi & Maachis

### Features
- SSO is Enabled in HaptikLib
- HPSignupObject changed to support Generic Auth Types


### Enhancements
- Add Assert for Requiring Application Instance
- Transaction History is Made iPhone X Compatible
- Objective-C Frameworks of Citrus are Added
- Feedback Generator is rewritten in Objective-C
- Referral Code Cell is rewritten in Objective-C
- Referral Redeem Cell is rewritten in Objective-C
- Web Self Serve is rewritten in Objective-C
- Image Gallery VC is rewritten in Objective-C
- Image CollectionView Cell is rewritten in Objective-C
- Swift is Completely Removed from HaptikLib


### Bugs
- Fix Title Clipping on Smart Forms Search
- Resolve Wallet Issue on Verifying Guest User
- Resolve Amount going `0` in Coupons Screen from Recharge
- Resolve Auto Switching of Postpaid to Prepaid in Recharge Screen
- Fix Layout of Conversation Screen for iOS 10 or less
- Fix Clear Chat Issue on Unread Messages
- Fix Guest Signup Bug on Postpaid (Recharge)
- Fix Push Notifications Issue for Verified User
- Fix a bug where Offers Screen was not being pushed from Wallet Scene
- Fix Extra Space Coming on Coupon Offers Scene
- Corrected wrong error message on Mobikwik Signin


---

## [0.4.0] - (17/03/18) - Jaane Bhi Do Yaaron

### Features
- Added Functionality to Update User's Auth Token/Code


### Enhancements
- Add Theming to HaptikDemo
- Added missing GuestSignup flows in HPFlowCoordinator
- Using last message timestamp to update Inbox Screen Table
- Handled Wallet Creation Notification
- User's Saved Addresses Fetched
- Using objectIDs for height caching on conversations screen
- Added Wallet Creation Dialog Check on Inbox
- Screen Title Copy is Updated in GuestSignup FLows
- Made Image Gallery View Controller iPhone X Compatible
- Added additional interface function to determine whether notification payload can be handled by SDK


### Bugs
- Corrected usage of shared suite user defaults for saving persistent configurations
- Resolved Syncing Issue in HPSyncEngine
- Resolved Archived Chats Filtration Bug
- Resolved GuestSignup Notification Issue
- Resolved late showing of Banners View on Inbox Screen
- Resolved Connected Wallets Crash
- Resolved Taskbox Creation Issue on Clear Chat
- Corrected animations on conversations screen
- Resolved Message Composer Issue on Conversations Screen
- Corrected duplicate unfilled chatforms being shown to user
- Corrected validation if self serve screen is kept blank and user taps on proceed button
- Drawing banners page controller only if more than one banners are available
- Fixed Black Bar Bug on SmartForms
- Removed PhonePe from HaptikLib

---

## [0.3.0] - (23/02/18) - Insaan

### Features
- Added Onboarding Loading Screen Functionality
- Added functionality to launch channels using specific viaName
- Unread Count of Inbox Chats provided
- Handled CleverTap Notifications & Deeplinking


### Enhancements
- Removed usage of deprecated functions
- Added validation checks for mobile number
- Added checks for succesful signup before transition to restricted channels
- Firing sync requests only on presentation SDK root inbox screen
- Performing intial setup for channels on initialising SDK
- Using standard defaults for storing sync update timestamps
- Setting MQTT end-points dynamically via user attributes
- Modified accesses to SDK init attributes
- Presenting Wallet Not Created Screen after Signup if required
- Handled Notification Flows from Clients Screen
- Add Inbox Scene in Notifications Flows
- MessageID is now used for Sorting Chat Messages


### Bugs
- Fix AmazonPay Payment Bug
- Corrected non-main queue accesses of UIKit objects
- Fix Notification Handling Bug


---

## [0.2.0] - (14/02/18) - Haider

### Features
- Added functionality for Guest User Signups on Basic Auth clients
- Add functionality to Check for Haptik Notification
- Give CleverTap Configuration to Clients and set up CleverTap Push Notifications
- Added Image Uploading Functionality
- Added functionality to handle push notifications triggered screen routing
- Added Offers Screen in HaptikLib


### Enhancements
- Modify User Parameters with Device Platform Change
- Modified flows for updating verified users
- Updated HaptikLib interfaces for public accesses
- Firing Sync Service requests on app launch
- Fetching lost messages via get_unreceived_messages on app launch
- Modified firing of network requests on initialization of SDK


### Bugs
- Resolved Image Uploading Error

---

## [0.1.0] - (30/01/18) - Gangs of Wasseypur

### Features
- PhonePe's SDK Integrated
- Added Image Gallery View Controller
- Added Rate and Share Functionality in HaptikLib


### Enhancements
- Conversation VC is made iPhone X Compatible
- Google Maps & Place Picker SDK's are Configured
- SVProgressHUD is Configured
- Running Build Script only on device installs
- CarouselDetailVC is made iPhone X Compatible
- CouponOffers VC is made iPhone X Compatible
- Access Location Permission for Testing Purpose
- Handled Referral Flow in Payments
- Removed Assistants Image from Feedback Overlay
- Handled Share & Earn Flow in Haptik Wallet
- Navigation Options are Provided on Inbox for Demo Application
- Uber Login is Handled through browser


### Bugs
- Resolved Banners Cropping Issue on iOS 9
- Reslolved Card Message Unread Bug
- Resolved selection of wrong time in Chatforms
- Resolved MultiSelect Picker Checkboxes not coming Bug
- Resolved SmartForms Search not working in Chatforms
- Resolved Banners Scrolling Issue for Single Banner Item
- Resolved Message Composer Layout Issue when Keyboard was showed
- Resolved Message Time Stamp not Coming on Inbox
- Resolved Business Name & Time Stamp Text Color Bug
- Resolved Deep Linker Issue
- Resolved Taskbox Presentation & Preview Text Issues
- Resolved Archiving Issue
- Resolved HaptikLib Crash on Payment Completion
- Resolve Banners not Showing up Issue
- Resolved App Crash Issue on URI Type LINK & WEBVIEW
- Resolved Hourly Banners Fetch Issue
- Resolved Wrong Preview Text on Inbox Issue
- Resolved Spelling Issues
- Resolved Payment Data Object Issue
- Resolved Freecharge & Mobiqwik Payments Issue
- Resolved Feedback View's cropping issue
- Resolved Coupons Table Cropping Issue in iOS 9
- Tasks Core Data class is made Protected
---

## [0.0.8] - (12/01/18) - English Vinglish

### Features
- Images are added in HaptikLib within Image Assets as well as in Folders
- Implemented Show/Hide Toggling of Archived Channels
- Module Map has been used to Inter-Operate between Private Objective-C Headers and Swift Files
- Added WebSelfServeScreen utilised via Tab List Element
- Haptic Feedback Generator Helper Added
- AmazonPay Added in HaptikLib
- CitrusPay Added in HaptikLib
- Added Haptik Wallet Functionality in HaptikLib
- Card Payment and Add New Card Functionalites added
- Added Core Location & Google Maps SDK dependent flows
- Added Saved Addresses Flows
- Added Cabs Flows
- Added Coupon Offers Flows
- Added Payment Options Flows
- Added Recharge Flows
- Added Transaction History Feature


### Enhancements
- Enhanced Inbox Cell to conform to all client Theme Configurations
- Provide Banners Toggling Functionality to Clients
- Refactored UIApplication object access from non-main queues
- Improvised folder hierarchy
- Removed SDWebImage dependency
- Added location dependency in Chatforms
- Removed Modular imports
- Added environment key in plist check while initializing SDK
- Used Images in HaptikLib's Bundle
- Enhanced Conversation VC and removed unused properties
- Updated MQTT library used in SDK
- Required Configurations are done to show Notifications in Demo App


### Bugs
- Resolved MHGallery Documentation build warnings
- Corrected Message Logger Bug where chat message was not being set in the Inbox Chat's Chat Message Property
- Resolved crash on animated presentation of Banners section
- Reslolved User2 PUT Call Issue
- Resolved User2 PUT Call crash by adding the missing location properties
- Resolved MQTT not connecting for already signed up users
- Resolved Card Message layout on Inbox screen
- Resolved User2 Put Call Failiure Case
---
