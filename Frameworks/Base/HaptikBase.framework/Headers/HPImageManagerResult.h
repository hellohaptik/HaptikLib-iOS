//
//  HPImageManagerResult.h
//  HaptikLib
//
//  Created by SimranJot Singh on 18/10/18.
//  Copyright © 2018 Haptik. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface HPImageManagerResult: NSObject


#pragma mark - Initializers

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithResult:(id)imageResult NS_DESIGNATED_INITIALIZER;


#pragma mark - Properties

@property (nonatomic, nullable, readonly) UIImage *image;

@property (nonatomic, nullable, readonly) NSError *error;

@end

NS_ASSUME_NONNULL_END
