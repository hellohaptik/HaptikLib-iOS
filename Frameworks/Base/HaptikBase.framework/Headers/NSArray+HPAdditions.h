//
//  NSArray+HPAdditions.h
//  HaptikBase
//
//  Created by SimranJot Singh on 25/07/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (HPAdditions)

/**
 Executes a given block using each object in the array, starting with the first object and continuing through the array to the last object.

 @param block The block to execute for each object in the array.
 */
- (void)hp_enumarateWithIndex:(void (^)(id object, NSUInteger index))block;

/**
 Loops over the collection and applies the same operation specified in the block to each element.
 
 @discussion
 The map function has a single argument which is a block that it calls as it loops over the collection.
 The block should taking the element from the collection as an argument should returns a result.
 The map function returns these results in an array.

 @param block The block to execute for each object in the array.
 @return Array containing the results of applying a mapping or transform function to each item.
 */
- (NSArray *)hp_map:(id (^)(id object))block;

/**
 Loop over the collection and returns an array containing only those elements that match an block condition.
 
 @discussion
 The filter method has a single argument which is a block that specifies the include condition.
 The block takes each element as an argument from the collection and must return a Bool indicating if the item should be included in the result.

 @param block The block to execute for each object in the array.
 @return Array containing the filtered objects
 */
- (NSArray *)hp_filter:(BOOL (^)(id object))block;

/**
 It combines all items in the collection to create a single new value.
 
 @discussion
 The initial value to begin accumlating here is taken as the value of the first object and the reduction is started from the second object

 @param block The block to execute for each object and accumulator in the array.
 @return The accumulated value after the collection is lopped over
 */
- (id)hp_reduce:(id (^)(id accumulator, id object))block;


/**
 It combines all items in the collection to create a single new value.

 @param initialValue optional initial value for the accumulator
 @param block The block to execute for each object and accumulator in the array.
 @return The accumulated value after the collection is lopped over
 */
- (id)hp_reduce:(nullable id)initialValue withBlock:(id (^)(id accumulator, id object))block;

@end

NS_ASSUME_NONNULL_END
