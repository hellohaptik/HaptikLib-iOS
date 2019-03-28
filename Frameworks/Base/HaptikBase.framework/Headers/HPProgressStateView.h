//
//  HPProgressStateView.h
//  HaptikBase
//
//  Created by SimranJot Singh on 28/02/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface HPProgressStateView : NSObject

+ (void)dismiss;

+ (BOOL)isVisible;

+ (void)showLoading;

+ (void)showWithDescription:(nullable NSString *)description;

+ (void)showErrorWithDescription:(nullable NSString *)description;

+ (void)showSuccessWithDescription:(nullable NSString *)description;

@end

NS_ASSUME_NONNULL_END
