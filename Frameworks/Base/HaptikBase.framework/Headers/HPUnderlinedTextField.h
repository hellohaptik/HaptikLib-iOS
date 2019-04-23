//
//  HPUnderlinedTextField.h
//  HaptikBase
//
//  Created by SimranJot Singh on 14/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


#import <HaptikBase/HPTextField.h>


NS_ASSUME_NONNULL_BEGIN

@interface HPUnderlinedTextField : HPTextField

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame
                  borderColor:(nullable UIColor *)borderColor
                    labelText:(nullable NSString *)labelText NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
