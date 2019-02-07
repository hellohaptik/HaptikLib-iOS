//
//  UIImageView+HPNetwork.h
//  HaptikLib
//
//  Created by Yogesh Singh on 03/11/17.
//  Copyright © 2017 Haptik. All rights reserved.
//


#import "HPImageManagerResult.h"


NS_ASSUME_NONNULL_BEGIN

@interface UIImageView (HPNetwork)


#pragma mark - Image Fetching Methods

- (void)hp_updateWithProgress:(BOOL)progress;

- (void)hp_setImageFromURLString:(NSString *)URLString
                placeholderImage:(nullable UIImage *)placeholderImage;

- (void)hp_setImageFromURLString:(NSString *)URLString
                placeholderImage:(nullable UIImage *)placeholderImage
                      completion:(void (^)(HPImageManagerResult * result))completion;


#pragma mark - Haptik Image Factory Methods

- (void)hp_setImage:(NSString *)imageName placeholderImage:(nullable UIImage *)placeholderImage;

- (void)hp_setImage:(NSString *)imageName placeholderImage:(nullable UIImage *)placeholderImage completion:(void (^)(HPImageManagerResult * result))completion;

@end

NS_ASSUME_NONNULL_END
