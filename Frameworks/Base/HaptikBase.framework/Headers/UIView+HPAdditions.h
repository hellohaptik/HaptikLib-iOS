//
//  UIView+HPAdditions.h
//  HaptikBase
//
//  Created by SimranJot Singh on 12/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface UIView (HPAdditions)

@property (nonatomic, assign) CGPoint $origin;

@property (nonatomic, assign) CGSize $size;

@property (nonatomic, assign) CGFloat $x, $y, $width, $height;

@property (nonatomic, assign) CGFloat $left, $top, $right, $bottom;

- (void)applyRoundCornersAt:(UIRectCorner)corners
                     radius:(CGFloat)radius
                borderColor:(nullable UIColor *)borderColor;

@end

NS_ASSUME_NONNULL_END
