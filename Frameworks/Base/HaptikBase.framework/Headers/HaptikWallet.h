//
//  HaptikWallet.h
//  HaptikBase
//
//  Created by SimranJot Singh on 12/01/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HaptikWallet : NSObject < NSSecureCoding >

@property (nonatomic, assign) BOOL created;

@property (nullable, nonatomic) NSNumber *balance;
@property (nullable, nonatomic) NSString *formattedBalanceTitle;

@property (nullable, nonatomic) NSNumber *credited_amount_month;
@property (nullable, nonatomic) NSNumber *max_credit_limit_month;
@property (nullable, nonatomic) NSNumber *max_wallet_balance_limit;

@end

NS_ASSUME_NONNULL_END
