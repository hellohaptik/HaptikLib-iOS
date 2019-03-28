//
//  UIColor+HPAdditions.h
//  HaptikBase
//
//  Created by SimranJot Singh on 12/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface UIColor (HPAdditions)


#pragma mark - Haptik Wide Colors

+ (UIColor *)bodyTextColor;
+ (UIColor *)disabledTextColor;
+ (UIColor *)lightHaptikGrayColor;


#pragma mark - UIColor Helper Methods

/**
 Using this helper method you don't need to first divide the respective RGBA values with 255 to convert them in the range of 0–1

 @param red Value of the red component
 @param green Value of the green component
 @param blue Value of the blue component
 @param alpha A number between 0.0 (fully transparent) and 1.0 (fully opaque).
 
 @return Returns the UIColor instance from the RGBA values passed.
 */
+ (UIColor *)colorFromRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
