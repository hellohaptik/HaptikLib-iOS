//
//  HPOfflineBotAPI.h
//  HaptikBase
//
//  Created by SimranJot Singh on 15/11/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#ifndef HPOfflineBotAPI_h
#define HPOfflineBotAPI_h

NS_ASSUME_NONNULL_BEGIN

@protocol HPOfflineBotAPI <NSObject>

@required

/// Business via name for the conversation
@property (nonatomic) NSString *viaName;

/// Runs the input on the offline model and generates the output
/// @param input Input to be provided to the model
/// @param locale Locale identifier in which the output is desired
/// @param completion After running the input on the model a completion block is called which contains the result
- (void)invokeModelForInput:(NSString *)input
                     locale:(NSString *)locale
                 completion:(void (^)(NSString * result, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* HPOfflineBotAPI_h */
