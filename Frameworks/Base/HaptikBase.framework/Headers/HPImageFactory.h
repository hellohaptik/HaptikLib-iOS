//
//  HPImageFactory.h
//  HaptikLib
//
//  Created by SimranJot Singh on 18/10/18.
//  Copyright © 2018 Haptik. All rights reserved.
//


#import "HPImageManagerResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface HPImageFactory : NSObject


#pragma mark - Image Downloaders

+ (void)downloadImageWithURLString:(NSString *)urlString completion:(void (^ _Nullable)(HPImageManagerResult * _Nonnull result))completion;

+ (void)downloadHaptikImageNamed:(NSString *)imageName completion:(void (^ _Nullable)(HPImageManagerResult * _Nonnull result))completion;


#pragma mark - Prefetcher Helpers

+ (nullable NSUUID *)prefetchImageForURLString:(NSString *)urlString;

+ (void)cancelTaskWithUUID:(NSUUID *)UUID;


#pragma mark - Image Cache Helpers

+ (BOOL)containsImageInCacheForKey:(NSString *)key;

+ (UIImage *)getCachedImageForKey:(NSString *)key;

+ (void)setImageToCache:(UIImage *)image forKey:(NSString *)key;

+ (UIImage *)getImageObjectFromDiskForKey:(NSString *)key;


#pragma mark - Image URL Helpers

+ (NSString *)getFetchURLForImage:(NSString *)imageName;

@end

NS_ASSUME_NONNULL_END
