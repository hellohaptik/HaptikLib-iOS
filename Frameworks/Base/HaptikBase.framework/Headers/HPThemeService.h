//
//  HPThemeService.h
//  HaptikBase - Haptik Personal Assistant SDK for iOS
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

/**
 A class method which builds the "HPThemeServiceBuilder" object and initalizes your "HPThemeService" object with the data provided.
 @param builderData : The builder data provided in the block.
 
 @discussion
 If you don't provide custom colors to HPThemeService then HaptikLib will use the default colors.
 
 It's mandatory to provide all the font's to HPThemeService. Haptik provides it's custom font files that you have to add in your project and register them in your info.plist file.
 HaptikLib will then automatically use them even if you don't pass the names in the builder.
 
 If you wish to use your own font, pass all the required fonts in the builder, else the SDK will give an assert and exit.
 
 @code
 
 [HPConfiguration shared].themeConfig = [HPThemeService buildWithData:^(HPThemeServiceBuilder * _Nullable builder) {
 
     builder.brandColor = [UIColor colorWithRed:(33/250.0) green:(150/255.0) blue:(243/255.0) alpha:1];
     builder.businessChatBackground = [UIColor colorWithRed:(240/255.0) green:(240/255.0) blue:(240/255.0) alpha:1];
     builder.businessChatText = [UIColor colorWithRed:(51/255.0) green:(51/255.0) blue:(51/255.0) alpha:1];
     builder.messageTimeStamp = [UIColor colorWithRed:(119/255.0) green:(119/255.0) blue:(119/255.0) alpha:1];
     builder.lightFont = @"SFUIText-Light";
     builder.regularFont = @"SFUIText-Regular";
     builder.mediumFont =  @"SFUIText-Medium";
 }];
 
 @endcode
 */
+ (instancetype)buildWithData:(void (^ _Nullable)(HPThemeServiceBuilder * _Nullable builder))builderData;

- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Theme Configuration Attributes

// Theme Colors

@property (nullable, nonatomic, readonly) UIColor *brandColor;

@property (nullable, nonatomic, readonly) UIColor *businessChatBackground;

@property (nullable, nonatomic, readonly) UIColor *businessChatText;

@property (nullable, nonatomic, readonly) UIColor *messageTimeStamp;


// Theme Fonts

@property (nullable, nonatomic, readonly) NSString *lightFont;

@property (nullable, nonatomic, readonly) NSString *regularFont;

@property (nullable, nonatomic, readonly) NSString *mediumFont;

@property (nullable, nonatomic, readonly) NSString *boldFont;

@property (nullable, nonatomic, readonly) NSString *semiBoldFont;

@property (nullable, nonatomic, readonly) NSString *italicFont;

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

@property (nullable, nonatomic) NSString *boldFont;

@property (nullable, nonatomic) NSString *semiBoldFont;

@property (nullable, nonatomic) NSString *italicFont;

- (HPThemeService *)build;

@end

NS_ASSUME_NONNULL_END

