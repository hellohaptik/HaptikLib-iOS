# CHANGELOG

This project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [2.6.8] - (18/03/21) - Quarter Khatam!

### Bugs
- Fix location picker coordinate issue

## [2.6.7] - (19/02/21) - Test 3 - CIA Down Under AI iOS

### Bugs
- Fix form data caching

## [2.6.6] - (05/02/21) - Test 2 - CIA Down Under AI iOS

### Bugs
- Fix memory crash

## [2.6.5] - (20/01/21) - Test 1 - CIA Down Under AI iOS

### Bugs
- Fix calendar date selection limit

## [2.6.4] - (25/09/20) - U iOS

### Enhancements
- Fix compatibility issue with Xcode12

### Bugs
- Fixes cell background color issue on RNHaptikLib

## [2.6.3] - (04/09/20) - S iOS

### Bugs
- Fixes feedback overlay issue

## [2.6.2] - (19/08/20) - R iOS

### Enhancements
- Added support for multi-line subtitles & description for Carousels.

### Bugs
- Fixes background thread error in Chatform search.

## [2.6.1] - (27/07/20) - P iOS

### Bugs
- Fixed network connection error

## [2.6.0] - (08/07/20) - O iOS

### Features
- Taskbox overlay can now be triggerd from backend

### Enhancements

- Added UI Tests for Location in Haptik Demo
- Added UI Tests for FeedbackViw in Haptik Demo
- Added UI Tests for Link and message in Haptik Demo
- Added UI Tests for file upload in Haptik Demo
- Added UI Tests for Carousel in Haptik Demo
- Updated analytics for Forms HSL 
- Updated SSL certificate
- Added support for `launch_inapp` for URI type `Link`

### Bugs

- Fixes overlapping of keyboard on feedback view
- Fixes low TTS volume
- Fixes URL redirections for URI type `LINK` 

---

## [2.5.0] - (09/04/20) - K iOS

### Features
- Document upload in chat supported
- Added restriction to enable camera only option
- Added Forms as a HSL Smart Action

### Enhancements
- Added UI Tests for Task Box in Haptik Demo
- Added UI Tests for Quick Reply in Haptik Demo
- Handled Reachability edge cases
- Removed Core-Data warnings

### Bugs
- Fixes sent form being display on successive launch
- Fixes contact picker field crash on simulators
- Lightweight migrations fixed
- Fixes Multithread violations

### Changed
- Default carousel width to medium
- Forms removed form sync

---

## [2.4.2] - (09/04/20) - F iOS

### Features

### Enhancements

### Bugs

### Changed
- Forces DB to reset on inconsistency exeptions.

---

## [2.4.1] - (03/04/20) - F iOS

### Features

### Enhancements
- Shared utilities made thread safe
- Haptik branding image updated

### Bugs
- Fixes navigation items showing wrong tint color
- Fixes background task error in CoreData.

---

## [2.4.0] - (26/03/20) - E iOS

### Features

### Enhancements
- Removed speed-test native action support
- Updated UIWebView with WKWebView implementation
- Rate & Share made optional
- Deprecated "notifyApplication:" method (no longer required to implement).

### Bugs
- Fixes composer not taking appropriate height on paste action

---

## [2.3.0] - (26/02/20) - D iOS

### Features

### Enhancements
- Deprecated MHGallery
- Deprecated Masonry
- Fonts made optional to configure

### Bugs
-  Corrected custom data syncing

---

## [2.2.3] - (17/02/20) - D iOS

### Features

### Enhancements
- Better Notification Handling

### Bugs

---

## [2.2.2] - (14/02/20) - D iOS

### Features

###Enhancements
- Updated documentation
- Added MQTT Safe checks 

### Bugs

---

## [2.2.1] - (05/02/20) - C iOS

### Features
- Allow custom data requests before chat initiation

### Enhancements
- Deprecated user details and settings scene

### Bugs
- Device Token not parsed correctly is fixed

---

## [2.2.0] - (13/01/20) - A iOS

### Features
- Enabled launch message capabilities

### Bugs

- Fixed User2 put call parsing
- Corrected message level feedback views on smaller devices
- Fixed resend message functionality
- Fixed user analytics crash

---

## [2.1.1] - (27/12/19) - C iOS

### Enhancements

- Restrict unnecessary push token update API calls

### Bugs

- Conversation closing on disissing Rate us is fixed

---

## [2.1.0] - (04/12/19) - A iOS

### Features

- Message level feedback functionality is added
- Offline conversation functionality added
- Analytics is abstracted out in a separate spec

### Enhancements

- Added Unit tests in `HaptikBase`
- Taskbox to be presented after every 8 minutes of last message sent
- Add loader animation in place picker when detecting user location
- Show location address while searching for places
- Removed support of i386 architecture from the SDK
- Analytics added for offline module
- Only active forms are fetched while syncing
- Use ChildVC for feedback overlay
- Refactor Location Module
- Refactor Localisation in HPConfiguration

### Bugs

- Fix place picker loader animation not being dismissed
- Fix unsafe typecasting crash while dismissing taskbox overlay

---

## [2.0.1] - (19/11/19) - Y iOS

### Bugs

- Fix back button not working if the conversation is presented modally

### Enhancements

- Haptik Branding is now configurable from the backend

---

## [2.0.0] - (04/11/19) - X iOS

### Features
- AutoLaunch actions of URI type `AUTOLAUNCH` are added
- Add analytics for Text to Speech and Speech to Text
- Add Support for Native TTS
- Blur the SDK screens when app goes in background
- Conversation sorting now supports offline messaging
- Add viaName extension to HPSignupObject to directly push to channel after signup

### Enhancements
- Extend language support to inbox 
- TTS will only occur for text in `voice_text` parameter
- Removed guest user verification 
- Removed `HaptikPayments` Support
- Removed Inbox screen
- Removed Cities related functionality
- Added Location functionality 
- Update `firstResponder` handling for location search
- Allow user entered feedback comments for one star feedback
- Disable submit feedback button when the user has not entered any feedback

### Bugs
- Fix typing indicator being shown for some time after language switch
- Fix Mic turn off sound being delayed when exiting conversation screen
- User Language not synced for new signup is fixed
- Fix bug where deactivated business were still shown in inbox
- TTS reading out random messages sometimes is fixed
- Fix Crash caused when opening new channel
- fix messages dissapearing on updating sdk
- Fix previous address sent for non-hsl location smartaction
- Fix location required tasks not being logged
- Fix HSL location smartaction response not formatted properly
- Fix location pin not being overlayed on user location
- Fix bug where STT would not be interrupted on redirecting user to map picker/web view
- Fix taskbox being dismissed when showing location picker for location required tasks
- Fix navigation stack not being arranged on receiving a background notification

---

## [1.8.2] - (16/10/19) - W iOS

### Enhancements

- New API for launching the conversation view directly

---

## [1.8.1] - (03/10/19) - U iOS

### Bugs

- Bitcode compilation issue is resolved
- SignupDataBuilder authentication fix

---

## [1.8.0] - (13/09/19) - Q iOS

### Features

- Added Language Support for hindi
- Native Communications bridge is added

### Enhancements

- CoreData architecture is revamped
- GoogleMaps dependency is removed from core
- Saved Addresses are not used anymore

### Bugs

- Conversation Scene fetching redundant messages is fixed
- Message Composer Bar height issue is fixed
- Fix voice permissions not being asked for later attempts after denying once
- Fix unread count bug for messages received while in other chat screens

---

## [1.7.2] - (23/08/19) - O iOS

### Bugs

- SDK crashing during social media login is fixed

---

## [1.7.1] - (21/08/19) - O iOS

### Features

- Voice features STT & TTS can now be turned off

---

## [1.7.0] - (5/07/19) - I iOS

### Features

- Haptik has now newly designed Taskbox
- WebSelfServe now supports flexible height functionality
- Haptik Speech Module is added for TTS & STT

### Enhancements

- Cabs is removed from HaptikLib

### Bugs

- Conversation Scene Distortion on Chatform is fixed
- Wrong webView height for negative values is fixed
- Payment Navigation Issues Fixed

---

## [1.6.0] - (08/04/19) - U iOS

### Features

- Payments is Modularised in HaptikLib. It's now optional to use.

### Enhancements

- SSO Dependency is removed from HaptikLib
- Dev Server configuraions are given

### Bugs

- Email validation crash on signup is fixed
- Wallet Balance displayed as (null) is fixed.

---

## [1.5.0] - (06/02/19) - Oh Bug Kal Aana

### Features

- New Base Module is Created for Modularising HaptikLib
- Support for new message type called SystemMessages is Provided

### Enhancements

- API Key is Deprecated and is not necessary to initialise HaptikLib
- FormFields Images are now accessed from Haptik's Server

### Bugs

- Inbox Scene Crashes and Bugs are Fixed
- GetUnreceivedMessages API Call is Fixed

---

## [1.4.1] - (11/12/18) - Lagi Shart

### Bugs

- Fixes previous coupon detail not showing on entering invalid promo code

---

## [1.4.0] - (05/12/18) - Keh Ke Loonga

### Features

- Convenience Fee is Added in Payments

### Bugs

- Fixes Coupons and Referral API Calls Failing Bug when the amount was in Float
- Fixes Haptik Wallet UI Distortion Bug when users balance was in Float
- Fixes Closing Balance Discremency in the WalletHistoryTableView and WalletHistoryDetailVC
- Fixes CleverTap Identity not found Fix

---

## [1.3.0] - (26/10/18) - Hasee to Phasee

### Features

- Payment Gateway is Migrated to PayU from CitrusPay

---

## [1.1.1] - (14/09/18) - Carpe Diem

### Bugs

- Resolved Migration Issue
- Corrected Mapping Model & Model Version

---

## [1.1.0] - (08/09/18) - Balwant Rai ke Bugs

### Enhancements

- Support for iOS 12
- Conversation Height Helper is Introduced to Tackle the Lagging Issue

### Bugs

- Inbox FRC Delegate is set properly
- Resolved deleted messages coming back due to incorrect getUnreceivedMessages flow
- Conversation Flicker Issue is Resolved
- HTML Tags Issue is Resolved

---

## [1.0.1] - (29/08/18) - Abba Dabba Jabba

### Enhancements

- Previously filled User Details are now updated for the user

### Bugs

- Core Data Section Offset Crash is Fixed
- Conversation Scene's Table's Data Source Exception Crash is Fixed
- Inbox Scene's estimatedRowHeight Crash is Fixed
- Fix the Initial Sync Check

---

## [1.0.0] - (21/08/18) - Zeher

### Enhancements

- HPAnalyticsService is made Public
- Redundant Params are removed from Triggering Bot on Channel Launching
- Allow Clients to use Custom CleverTap Account on Staging & Dev Environment

### Bugs

- Offers Scene Title Tint is Fixed
- Conversation Connecting Spinner is Tinted to Navigation Items Tint
- Fixed a bug where user was not taken to Conversation Scene on Payment Success.
- Pushing of Not Required View Controller is Fixed
- Fixed the TabList Title Not Showing Issue
- Fixed the Date-String Parsing Issue

---

## [0.6.7] - (14/08/18) - Yamla Pagla Deewana

### Enhancements

- Recharge URL's are Updated

### Bugs

- Third Party Wallets not showing up on Logout State is Fixed
- Logging Issue is fixed for CleverTap Analytics

---

## [0.6.6] - (31/07/18) - X-Men

### Enhancements

- Negative Response Options are Updated

---

## [0.6.5] - (27/07/18) - Waigankar

### Features

- New Home Screen is Integrated
- Logout Feature is Given to Clients

### Bugs

- Fix Share Action not Working for Share Actionable
- Rate & Share is Fixed in RechargeVC
- SDK Crashing on Logging in again after SignOut is Fixed
- MQTT not connecting back after SignOut is Fixed.

---

## [0.6.4] - (17/07/18) - Vicky Donor

### Bugs

- Share & Rate not taking Client Applications Name is Fixed
- Previously HaptikLib was Dynamically Registering Fonts on Initialization which was causing crash in some scenarios, now the fonts are to registered by the clients itself to keep it consistent.
- Previously Entered Text coming in ChatForm is Fixed
- Rate Us Taking to Haptik App Store is Fixed

---

## [0.6.1] - (04/07/18) - Udta Punjab

### Enhancements

- Implementation of Configuring Navigation Bar for SDK ViewControllers is enhanced to accomodate more configurations and will now not affect the configurations globally across the client application.

### Bugs

- Taskbox not showing-up on launching a channel directly is fixed.
- ChatForm Getting Updated even on Form-Field type Search is fixed.

---

## [0.6.0] - (06/06/18) - Raabta

### Features

- Support for toggling Inbox Scene is Given

### Bugs

- Crash on pushing Conversation Scene directly with a message is fixed.

---

## [0.5.1] - (16/05/18) - Oh My God!

### Bugs

- CleverTap Issue is Resolved where Swift Clients were not able to cast AppDelegate.

---

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