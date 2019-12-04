//
//  NSDictionary+HPAdditions.h
//  HaptikBase
//
//  Created by SimranJot Singh on 13/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (HPAdditions)

- (NSString *)JSONString;


#pragma mark - Safe Access Helpers

// Collections

- (BOOL)hasKey:(NSString *)key;

- (BOOL)boolForKey:(id)key;

- (NSString *)stringForKey:(id)key;

- (NSNumber *)numberForKey:(id)key;

- (NSArray *)arrayForKey:(id)key;

- (NSDictionary *)dictionaryForKey:(id)key;

- (NSInteger)integerForKey:(id)key;

- (NSDate *)dateForKey:(id)key dateFormat:(NSString *)dateFormat;

// Primitives

- (int16_t)int16ForKey:(id)key;

- (int32_t)int32ForKey:(id)key;

- (int64_t)int64ForKey:(id)key;

- (char)charForKey:(id)key;

- (short)shortForKey:(id)key;

- (float)floatForKey:(id)key;

- (double)doubleForKey:(id)key;

- (long long)longLongForKey:(id)key;

- (unsigned long long)unsignedLongLongForKey:(id)key;

// Core Graphics

- (CGFloat)CGFloatForKey:(id)key;

- (CGPoint)pointForKey:(id)key;

- (CGSize)sizeForKey:(id)key;

- (CGRect)rectForKey:(id)key;

@end


@interface NSMutableDictionary (HPAdditions)

- (void)setObjectOrNil:(id)object forKey:(id)key;

@end

NS_ASSUME_NONNULL_END
