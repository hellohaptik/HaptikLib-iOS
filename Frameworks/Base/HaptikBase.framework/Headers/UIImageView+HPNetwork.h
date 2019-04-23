//
//  UIImageView+HPNetwork.h
//  HaptikBase
//
//  Created by SimranJot Singh on 27/02/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

@class HPImageManagerResult;

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

- (void)hp_setHaptikImage:(NSString *)imageName placeholderImage:(nullable UIImage *)placeholderImage;

- (void)hp_setHaptikImage:(NSString *)imageName placeholderImage:(nullable UIImage *)placeholderImage completion:(void (^)(HPImageManagerResult * result))completion;

@end

NS_ASSUME_NONNULL_END
