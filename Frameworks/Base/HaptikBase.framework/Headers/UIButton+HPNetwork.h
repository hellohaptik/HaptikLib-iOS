//
//  UIButton+HPNetwork.h
//  HaptikBase
//
//  Created by SimranJot Singh on 09/11/17.
//  Copyright © 2017 Haptik. All rights reserved.
//


#import "HPImageManagerResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (HPNetwork)


#pragma mark - Image Fetching Methods

- (void)hp_updateWithProgress:(BOOL)progress;

- (void)hp_setImageFromURLString:(NSString *)urlString
                placeholderImage:(nullable UIImage *)placeholderImage;

- (void)hp_setImageFromURLString:(NSString *)urlString
                placeholderImage:(nullable UIImage *)placeholderImage
                      completion:(void (^)(HPImageManagerResult * result))completion;


#pragma mark - Haptik Image Fetching Methods

- (void)hp_setHaptikImage:(NSString *)imageName placeholderImage:(nullable UIImage *)placeholderImage;

- (void)hp_setHaptikImage:(NSString *)imageName placeholderImage:(nullable UIImage *)placeholderImage completion:(void (^)(HPImageManagerResult * result))completion;

@end

NS_ASSUME_NONNULL_END
