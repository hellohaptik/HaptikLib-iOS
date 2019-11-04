//
//  HPLocationAPI.h
//  HaptikBase
//
//  Created by HAP-86 on 10/10/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


/**
 @param status returns  YES  if location was picked successfully else NO
 @param locationStr returns location coordinates of the picked place in "LAT,LON" format
 @param addressStr returns  an user readable address of the picked location
 */
typedef void (^HPLocationPickerCompletionHandler)(BOOL status, NSString *locationStr, NSString *addressStr);

@protocol HPLocationAPI <NSObject>

@required

/**
 @abstract
 Provide the user a Locatoin Picker from where he can pick  an address/ location
 
 @discussion
 This method will return a map picker VC which you can put on top of your VC
 use the completion block to handle success / error  etc.
 
 @param completion Completion block called after users cancels or picks a place
 
 @return A UIViewController containing Location Picker that can be pushed on top of your current VC
 */
- (UIViewController *)getLocationPicker:(HPLocationPickerCompletionHandler) completion;

@end
