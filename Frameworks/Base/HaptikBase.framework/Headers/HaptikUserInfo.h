//
//  HaptikUserInfo.h
//  HaptikBase
//
//  Created by SimranJot Singh on 23/01/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <HaptikBase/HaptikUser.h>
#import <HaptikBase/HaptikWallet.h>

NS_ASSUME_NONNULL_BEGIN

#define HPUserInfo  [HaptikUserInfo sharedInstance]

@interface HaptikUserInfo : NSObject

+ (instancetype)sharedInstance;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Attributes

@property (nonatomic, nullable, readonly) HaptikUser *attributes;


#pragma mark - Methods

- (void)saveInfo;

- (void)updateUserWith:(HaptikUser *)user;

- (void)resetWallet;

- (nullable NSError *)deleteUserInfo;

@end

NS_ASSUME_NONNULL_END
