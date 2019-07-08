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

- (void)pinAllEdgesOfSubview:(UIView *)subView;

/**
 Returns the view constraints matching a specific layout attribute (top, bottom, left, right, leading, trailing, etc.)
 
 @param attribute The layout attribute to use for searching.
 @return An array of matching constraints.
 */
- (nullable NSArray *)constraintsForAttribute:(NSLayoutAttribute)attribute;

/**
 Returns a layout constraint matching a specific layout attribute and relationship between 2 items, first and second items.
 
 @param attribute The layout attribute to use for searching.
 @param first The first item in the relationship.
 @param second The second item in the relationship.
 @return A layout constraint.
 */
- (nullable NSLayoutConstraint *)constraintForAttribute:(NSLayoutAttribute)attribute firstItem:(id __nullable)first secondItem:(id __nullable)second;

/**
 Animates the view's constraints by calling layoutIfNeeded.
 
 @param bounce YES if the animation should use spring damping and velocity to give a bouncy effect to animations.
 @param options A mask of options indicating how you want to perform the animations.
 @param animations An additional block for custom animations.
 */
- (void)animateLayoutIfNeededWithBounce:(BOOL)bounce
                                options:(UIViewAnimationOptions)options
                             animations:(void (^ __nullable)(void))animations;

- (void)animateLayoutIfNeededWithBounce:(BOOL)bounce
                                options:(UIViewAnimationOptions)options
                             animations:(void (^ __nullable)(void))animations
                             completion:(void (^ __nullable)(BOOL finished))completion;

/**
 Animates the view's constraints by calling layoutIfNeeded.
 
 @param duration The total duration of the animations, measured in seconds.
 @param bounce YES if the animation should use spring damping and velocity to give a bouncy effect to animations.
 @param options A mask of options indicating how you want to perform the animations.
 @param animations An additional block for custom animations.
 */
- (void)animateLayoutIfNeededWithDuration:(NSTimeInterval)duration
                                   bounce:(BOOL)bounce
                                  options:(UIViewAnimationOptions)options
                               animations:(void (^ __nullable)(void))animations
                               completion:(void (^ __nullable)(BOOL finished))completion;

@end

NS_ASSUME_NONNULL_END
