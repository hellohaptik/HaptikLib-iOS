//
//  HPImageFactory.h
//  HaptikBase
//
//  Created by SimranJot Singh on 18/10/18.
//  Copyright © 2018 Haptik. All rights reserved.
//


#import <HaptikBase/HPImageManagerResult.h>

#import <HaptikBase/HPSharedConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface HPImageFactory : NSObject


#pragma mark - Image Downloaders

+ (void)downloadImageWithURLString:(NSString *)urlString completion:(void (^ _Nullable)(HPImageManagerResult * _Nonnull result))completion;

+ (void)downloadHaptikImageNamed:(NSString *)imageName completion:(void (^ _Nullable)(HPImageManagerResult * _Nonnull result))completion;


#pragma mark - Haptik In-App Images

+ (nullable UIImage *)haptikImageNamed:(NSString *)imageName fromBundle:(NSBundle *)moduleBundle;


#pragma mark - Prefetcher Helpers

+ (nullable NSUUID *)prefetchImageForURLString:(NSString *)urlString;

+ (void)cancelTaskWithUUID:(NSUUID *)UUID;


#pragma mark - Image Cache Helpers

+ (BOOL)containsImageInCacheForKey:(NSString *)key;

+ (UIImage *)getCachedImageForKey:(NSString *)key;

+ (void)setImageToCache:(UIImage *)image forKey:(NSString *)key;

+ (UIImage *)getImageObjectFromDiskForKey:(NSString *)key;


#pragma mark - Haptik Server Images URL Helpers

+ (NSString *)getFetchURLForHaptikImage:(NSString *)imageName;


#pragma mark - Image Resizing Helpers

+ (UIImage *)resizePNGImage:(UIImage *)image toSize:(CGSize)size;

+ (UIImage *)getPDFImage:(NSString *)image fromBundle:(NSBundle *)resourceBundle;

+ (UIImage *)getResizedPDFImage:(NSString *)imageName fromBundle:(NSBundle *)resourceBundle toSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
