//
//  HPWebService.h
//  HaptikLib
//
//  Created by Yogesh Singh on 05/10/17.
//  Copyright © 2017 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface HPWebService : NSObject

+ (NSURLSessionDataTask *)getDataTaskFor:(NSURLRequest *)request
                              completion:(void (^ _Nullable)(id _Nullable serializedObject, NSURLResponse *_Nullable headers, NSError *_Nullable error))completion;


+ (void)dataRequest:(NSURLRequest *)request
         completion:(void (^ _Nullable)(id _Nullable serializedObject, NSURLResponse *_Nullable headers, NSError *_Nullable error))completion;


+ (NSMutableURLRequest *)requestForMethod:(NSString *)method
                                URLString:(NSString *)URLString
                                   params:(NSDictionary *_Nullable)params
                                    error:(NSError *_Nullable __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
