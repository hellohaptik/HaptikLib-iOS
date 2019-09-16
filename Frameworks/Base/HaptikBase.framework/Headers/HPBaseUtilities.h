//
//  HPBaseUtilities.h
//  HaptikBase
//
//  Created by SimranJot Singh on 03/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface HPBaseUtilities : NSObject


#pragma mark - HaptikLib Credential Helpers

/**
 *  Returns the HaptikLib Info Dictionary in the info.plist file.
 */
+ (NSDictionary *)haptikLibCredentialsInfoDict;

/**
 *  Returns the clientID provied in HaptikLib Dictionary in the info.plist file.
 *  It's necessary to provide this argument there else HaptikLib will exit with an assert on initialization.
 */
+ (NSString *)clientID;

/**
 *  Returns the baseURL provied in HaptikLib Dictionary in the info.plist file.
 *  It's necessary to provide this argument there else HaptikLib will exit with an assert on initialization.
 */
+ (NSString *)baseURL;

/**
 *  Returns the runEnvironment provied in HaptikLib Dictionary in the info.plist file.
 *  It's necessary to provide this argument there else HaptikLib will exit with an assert on initialization.
 */
+ (NSString *)runEnvironment;

/**
 *  Returns the CleverTapDict provied in HaptikLib Dictionary in the info.plist file.
 */
+ (NSDictionary *)getCleverTapDict;

/**
 *  Returns the shareAndRateDict provied in HaptikLib Dictionary in the info.plist file.
 */
+ (NSDictionary * _Nullable)shareAndRateDict;

/**
 *  Returns the appStoreURL provied in HaptikLib Dictionary in the info.plist file.
 */
+ (NSString * _Nullable)appStoreURL;

/**
 *  Returns the iTunesItemIdentifier provied in HaptikLib Dictionary in the info.plist file.
 */
+ (NSString * _Nullable)iTunesItemIdentifier;

/**
 *  Returns the running applications name (CFBundleDisplayName).
 */
+ (NSString *)getRunningApplicationsName;

/**
 *  Returns a bool incdicating if the current environment is set to production or not.
 */
+ (BOOL)isProductionEnvironment;

/**
 *  The method returns the same dictionary(shareAndRate) that the client added in the HaptikLib's Credentials
 *  Dictionay (only HPShareUrl & HPShareText) in their info.plist file with HPShareUrl replaced at respective places.
 *  If the values are not added then by default Haptik is shared with its custom text.
 */
+ (NSDictionary<NSString *,NSString *> *)getApplicationShareInfo;

@end

NS_ASSUME_NONNULL_END
