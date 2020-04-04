//
//  HPConfiguration.h
//  HaptikBase
//
//  Created by SimranJot Singh on 22/02/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


@class HPThemeService;

#import <HaptikBase/HPAnalyticsService.h>

#import <HaptikBase/HPAnalyticsAPI.h>
#import <HaptikBase/HPMessagingListenerAPI.h>

NS_ASSUME_NONNULL_BEGIN

@interface HPConfiguration : NSObject

#define HaptikConfigs [HPConfiguration shared]
#define HPLanguages [NSArray arrayWithObjects:@"hi",@"en", nil]

/**
 *  Returns the shared instance of HPConfiguration
 */
+ (instancetype)shared;

/**
 *  HPConfiguration is a singleton class. Default Initializer is not available.
 */
- (instancetype)init NS_UNAVAILABLE;


#pragma mark - Attributes

/**
 *  Analytics Callback Object
 *  If provided, Analytics Service Class will send delegate callbacks to the provided delegate self.
 */
@property (nullable, nonatomic, weak) id <HPAnalyticsServiceDelegate> analyticsCallbackObject;

/**
 Messaging Listener Object
 If the object is confirmed by any class, the SDK will try to ask for some data needed for a Haptik's Chat Message from the application through the methods provided in the HPMessagingListenerAPI.
 */
@property (nullable, nonatomic, weak) id <HPMessagingListenerAPI> messagingListenerObject;

/**
 Sets HPThemeService Object used for applying Theming Configurations
 
 @code
 
 [HPConfiguration shared].themeConfig = [HPThemeService buildWithData:^(HPThemeServiceBuilder * _Nullable builder) {
 
     builder.brandColor = [UIColor colorWithRed:(33/250.0) green:(150/255.0) blue:(243/255.0) alpha:1];
     builder.businessChatBackground = [UIColor colorWithRed:(240/255.0) green:(240/255.0) blue:(240/255.0) alpha:1];
     builder.businessChatText = [UIColor colorWithRed:(51/255.0) green:(51/255.0) blue:(51/255.0) alpha:1];
     builder.messageTimeStamp = [UIColor colorWithRed:(119/255.0) green:(119/255.0) blue:(119/255.0) alpha:1];
     builder.lightFont = @"HelveticaNeue-Light";
     builder.regularFont = @"HelveticaNeue";
     builder.mediumFont =  @"HelveticaNeue-Medium";
     builder.boldFont =  @"HelveticaNeue-Bold";
     builder.italicFont =  @"HelveticaNeue-Italic";
 }];
 
 @endcode
 */
@property (nonatomic) HPThemeService *themeConfig;

/*
 *  Language used by the SDK
 */
@property (nonatomic, readonly) NSString *currentHaptikLocale;

/**
 *  Set Use Voice BOOL
 *  This BOOL controls the voice support of Haptik. This will determine if the user can interact via voice using TTS/STT. By default the value will be true.
 */
@property (nonatomic, assign) BOOL useVoice;

/**
 *  Set useNativeTTS BOOL
 *  When set TRUE this will use the offline native TTS, the default option will be an online TTS service
 */
@property (nonatomic, assign) BOOL useNativeTTS;


#pragma mark - Getters

/**
 *  Gets you the current theme themeConfig's brandColor. If you haven't set your custom themeConfig, it will return its default value.
 */
- (UIColor *)brandColor;

/**
 *  Gets you the current theme themeConfig's businessChatBackground. If you haven't set your custom themeConfig, it will return its default value.
 */
- (UIColor *)businessChatBackground;

/**
 *  Gets you the current theme themeConfig's businessChatText. If you haven't set your custom themeConfig, it will return its default value.
 */
- (UIColor *)businessChatText;

/**
 *  Gets you the current theme themeConfig's messageTimeStamp. If you haven't set your custom themeConfig, it will return its default value.
 */
- (UIColor *)messageTimeStamp;

/**
 *  Gets you the current theme themeConfig's lightFont name. If you haven't set your custom themeConfig, it will return its default value.
 */
- (NSString *)lightFont;

/**
 *  Gets you the current theme themeConfig's regularFont name. If you haven't set your custom themeConfig, it will return its default value.
 */
- (NSString *)regularFont;

/**
 *  Gets you the current theme themeConfig's mediumFont name. If you haven't set your custom themeConfig, it will return its default value.
 */
- (NSString *)mediumFont;

/**
 *  Gets you the current theme themeConfig's boldFont name. If you haven't set your custom themeConfig, it will return its default value.
 */
- (NSString *)boldFont;

/**
 *  Gets you the current theme themeConfig's italicFont name. If you haven't set your custom themeConfig, it will return its default value.
 */
- (NSString *)italicFont;


#pragma mark - Helpers

/**
 @abstract
 Allows SDK Clients to modify the appearance of navigation bar of HaptikLib's View Controllers
 
 @param barTintColor Color to be used for tinting the navigation bar. Defaults to default navigation bar tint of iOS
 @param barItemTintColor Used to set the tint color of the navigation items. This is used for the HaptikLib's viewControllers navigation items. Default color is [UIColor blackColor];
 @param translucent BOOL value to set the translucent property of navigation bar. Default is NO
 @param navigationController Instance of the navigationController for which the configurations are to be done
 
 @discussion
 The params barTintColor is nullable, i.e. you can pass nil if you want it to be set to default (don't want to set).
 
 @code
 
 [[HPConfiguration shared] configureNavigationBarTintColor:[UIColor redColor]
                                   navigationItemTintColor:[UIColor whiteColor]
                                           makeTranslucent:NO
                                   forNavigationController:navController];
 
 @endcode
 */
- (void)configureNavigationBarTintColor:(nullable UIColor *)barTintColor
                navigationItemTintColor:(nullable UIColor *)barItemTintColor
                        makeTranslucent:(BOOL)translucent
                forNavigationController:(UINavigationController *)navigationController;

/**
 @abstract
 Get's you an instance of UINavigationController embedding the passed viewController as it's rootViewController.
 
 @param viewController vieController to embedd as rootViewController
 
 @code
 
 [[HPConfiguration shared] embeddInNavigationController:viewController];
 
 @endcode
 */
- (UINavigationController *)embeddInNavigationController:(__kindof UIViewController *)viewController;


/**
 Set the language that will be used in the SDK

 @param locale language Code from HPlanguages array which is to be set
 @param completion this block will be called with TRUE if language change is sucessful else FALSE
 */
- (void)setHaptikLocale:(NSString *)locale with:(void (^ _Nullable)(BOOL success))completion;

@end

NS_ASSUME_NONNULL_END
