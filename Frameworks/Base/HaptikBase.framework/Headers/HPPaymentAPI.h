//
//  HPPaymentAPI.h
//  HaptikBase
//
//  Created by SimranJot Singh on 18/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@protocol HPPaymentAPI <NSObject>

typedef NS_ENUM(NSUInteger, HPRechargeTabType) {
    
    RechargeTabTypeMobile = 0,
    RechargeTabTypeDTH,
    RechargeTabTypeElectricity
};

typedef NS_ENUM(NSUInteger, HPWalletTabType) {
    
    WalletTabTypeBalance = 0,
    WalletTabTypeHistory
};


@required

+ (void)pushToRechargeFrom:(__kindof UIViewController *)source
              businessData:(NSDictionary *)businessData
           transactionData:(nullable NSDictionary *)transactionData
               selectedTab:(HPRechargeTabType)selectedTab;


+ (void)pushToCouponOffersFrom:(__kindof UIViewController *)source
                   paymentData:(NSDictionary *)paymentData;


+ (void)pushToHaptikWalletFrom:(__kindof UIViewController *)source
                   selectedTab:(HPWalletTabType)selectedTab;


+ (void)pushToPaymentTransactionsFrom:(__kindof UIViewController *)source
                         businessData:(NSDictionary *)businessData;


+ (void)pushToSavedCardsFrom:(__kindof UIViewController *)source;


+ (void)fetchHaptikWalletDetails:(void (^ _Nullable)(BOOL success, NSError *error))completion;

+ (Class)getRechargeClass;

+ (Class)getHaptikWalletClass;

+ (Class)getPaymentTransactionsClass;

+ (BOOL)isRedirectHandledForURL:(NSURL *)url;


@end

NS_ASSUME_NONNULL_END
