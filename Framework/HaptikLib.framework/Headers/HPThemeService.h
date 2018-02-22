//
//  HPThemeService.h
//  HaptikLib - Haptik Personal Assistant SDK for iOS
//
//  Copyright © 2018 Haptik. All rights reserved.
//
//  Usage of this SDK is subject to the Haptik Terms of
//  Service: https://haptik.ai/terms-conditions
//


#import <UIKit/UIKit.h>

@class HPThemeServiceBuilder;


NS_ASSUME_NONNULL_BEGIN

@interface HPThemeService : NSObject


#pragma mark - Theme Service Initialier

/*
 *  A class method which builds the "HPThemeServiceBuilder" object and initalizes your "HPThemeService" object with the data provided.
 *  @param builderData : The builder data provided in the block.
 */
+ (instancetype)buildWithData:(void (^ _Nullable)(HPThemeServiceBuilder * _Nullable builder))builderData;

- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Theme Configuration Attributes

#pragma mark Colors

@property (nullable, nonatomic, readonly) UIColor *brandColor;

@property (nullable, nonatomic, readonly) UIColor *businessChatBackground;

@property (nullable, nonatomic, readonly) UIColor *businessChatText;

@property (nullable, nonatomic, readonly) UIColor *messageTimeStamp;


#pragma mark Fonts

@property (nullable, nonatomic, readonly) NSString *lightFont;

@property (nullable, nonatomic, readonly) NSString *regularFont;

@property (nullable, nonatomic, readonly) NSString *mediumFont;

@end


/*--------------------------------------------*/


#pragma mark - Theme Service Builder

@interface HPThemeServiceBuilder : NSObject

@property (nullable, nonatomic) UIColor *brandColor;

@property (nullable, nonatomic) UIColor *businessChatBackground;

@property (nullable, nonatomic) UIColor *businessChatText;

@property (nullable, nonatomic) UIColor *messageTimeStamp;

@property (nullable, nonatomic) NSString *lightFont;

@property (nullable, nonatomic) NSString *regularFont;

@property (nullable, nonatomic) NSString *mediumFont;


- (HPThemeService *)build;

@end

NS_ASSUME_NONNULL_END

