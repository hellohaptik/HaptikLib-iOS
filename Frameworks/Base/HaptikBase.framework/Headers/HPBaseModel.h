//
//  HPBaseModel.h
//  HaptikBase
//
//  Created by SimranJot Singh on 01/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface HPBaseModel : NSObject

+ (instancetype)modelObjectWithDictionary:(nullable NSDictionary *)dict;

- (nullable id)optionalObjectForKey:(nullable id)key fromDictionary:(nullable NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
