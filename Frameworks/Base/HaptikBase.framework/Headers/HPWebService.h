//
//  HPWebService.h
//  HaptikBase
//
//  Created by SimranJot Singh on 22/01/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HPWebService : NSObject

#pragma mark - Default Session Service

+ (void)performRequestFor:(NSString *)URLString
                   method:(NSString *)method
                   params:(nullable NSDictionary *)params
               completion:(void (^ _Nullable)(id _Nullable serializedObject, NSURLResponse *_Nullable headers, NSError *_Nullable error))completion;


#pragma mark -

+ (NSURLSessionDataTask *)getDataTaskFor:(NSURLRequest *)request
                              completion:(void (^ _Nullable)(id _Nullable serializedObject, NSURLResponse *_Nullable headers, NSError *_Nullable error))completion;


+ (void)dataRequest:(NSURLRequest *)request
         completion:(void (^ _Nullable)(id _Nullable serializedObject, NSURLResponse *_Nullable headers, NSError *_Nullable error))completion;


+ (void)uploadImage:(UIImage *)image
          urlString:(NSString *)urlString
             params:(NSDictionary *)params
         completion:(void (^ _Nullable)(id _Nullable serializedObject, NSError * _Nullable error))completion;


#pragma mark - Bill Payments Session Service

+ (void)dataRequest:(NSURLRequest *)request
setCompletionBlockWithSuccess:(void (^ _Nullable)(NSData *dataObject, NSURLResponse *response))success
            failure:(void (^ _Nullable)(NSError *error))failure;


+ (NSURLSessionDataTask *)getPlanListForServiceProvider:(NSNumber *)operatorID
                                               inCircle:(NSNumber *)circleID
                                            forCategory:(nullable NSNumber *)categoryID
                                             withAmount:(nullable NSNumber *)amount
                          setCompletionBlockWithSuccess:(void (^ _Nullable)(NSData *dataObject, NSURLResponse * response))success
                                                failure:(void (^ _Nullable)(NSError * error))failure;


#pragma mark - Request Serializer

+ (NSURL *)createGETRequestUrlWith:(NSString *)URLString params:(NSDictionary *)params;


+ (NSMutableURLRequest *)requestForMethod:(NSString *)method
                                URLString:(NSString *)URLString
                                   params:(nullable NSDictionary *)params
                                    error:(NSError *_Nullable __autoreleasing *)error;


+ (NSMutableURLRequest *)requestForMethod:(NSString *)method
                                URLString:(NSString *)URLString
                                   params:(nullable NSDictionary *)params
                              cachePolicy:(NSURLRequestCachePolicy)cachePolicy
                          timeoutInterval:(NSUInteger)timeoutInterval
                                    error:(NSError *_Nullable __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
