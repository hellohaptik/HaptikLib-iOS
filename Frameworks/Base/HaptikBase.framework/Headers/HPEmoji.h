//
//  HPEmoji.h
//  Haptik
//
//  Created by Yogesh Singh on 21/07/16.
//  Copyright © 2016 Haptik Inc. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface HPEmoji : NSObject

+ (NSAttributedString *)getEmojiAttributedTextFrom:(NSString *)string
                                withTextAttributes:(nullable NSDictionary<NSAttributedStringKey, id> *)textAttributes
                                        completion:(void (^ _Nullable )(NSAttributedString * _Nullable attributedString))completion;

@end

NS_ASSUME_NONNULL_END
