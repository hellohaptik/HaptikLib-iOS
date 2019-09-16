//
//  HPMessagingListenerAPI.h
//  HaptikBase
//
//  Created by SimranJot Singh on 29/07/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol HPMessagingListenerAPI <NSObject>

/**
 If the clients application confirms to the `messagingListenerObject` of HPConfiguration, the SDK will fire these methods through the confirmed object to get some data from the application for updating data in the Haptiks Chat Message
 
 @discussion
 The contracts for the `actionType` and the `resultsDict` needs to be pre-decided by both the parties before.

 @param actionType telling which action to be trigerred by the application
 @param actionParams Parameters required to perform the operation
 @param resultHandler The result passed by the application to the SDK after the action is performed. This can be called multiple times too.
 */
- (void)performAppActionFor:(NSString *)actionType
               actionParams:(NSArray<NSString *> *)actionParams
              resultHandler:(void (^)(NSDictionary * _Nonnull resultsDict))resultHandler;

@end

NS_ASSUME_NONNULL_END
