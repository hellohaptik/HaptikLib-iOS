//
//  HPTextField.h
//  HaptikBase
//
//  Created by SimranJot Singh on 14/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface HPTextField : UITextField

@property (nonatomic) NSString *regex;
@property (nonatomic) NSUInteger maxLength;
@property (nonatomic) UIColor *validatedColor;
@property (nonatomic, nullable) NSString *tagString;

@property (nonatomic) BOOL isProtectedField;
@property (nonatomic, readonly) BOOL isValidated;

@property (nonatomic, nullable) void (^tapAction)(void);
@property (nonatomic, nullable) void (^textChanged)(NSString *text);

- (BOOL)validateText:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
