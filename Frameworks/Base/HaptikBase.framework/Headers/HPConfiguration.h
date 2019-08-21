//
//  HPConfiguration.h
//  HaptikBase
//
//  Created by SimranJot Singh on 22/02/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


@class HPThemeService;

#import <HaptikBase/HPAnalyticsService.h>

NS_ASSUME_NONNULL_BEGIN

@interface HPConfiguration : NSObject

#define HaptikConfigs [HPConfiguration shared]

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
 Sets HPThemeService Object used for applying Theming Configurations
 
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
@property (nonatomic) HPThemeService *themeConfig;

/**
 *  Set Use Inbox BOOL
 *  This BOOL controls the visibility of Inbox Scene of Haptik. By default the value will be true.
 */
@property (nonatomic, assign) BOOL useInbox;

/**
 *  Set Use Voice BOOL
 *  This BOOL controls the voice support of Haptik. This will determine if the user can interact via voice using TTS/STT. By default the value will be true.
 */
@property (nonatomic, assign) BOOL useVoice;

/**
 *  Set Use InteractivePopGesture BOOL
 *  This BOOL controls the functionality of the EdgePanGestureRecognizer feature of UINavigationController that allows to set
 *  the slide to go back functionality for Haptik Screens. By default the value will be true.
 */
@property (nonatomic, assign) BOOL useInteractivePopGesture;

/**
 *  Set Use Referrals BOOL
 *  This BOOL controls the use of Referral Flows in Haptik. By default the value will be false.
 */
@property (nonatomic, assign) BOOL shouldUseReferrals;

/**
 *  Sets the Custom Title text to be shown on the Loading Screen. If not provided, default text will be shown.
 */
@property (nullable, nonatomic) NSString *loadingTitleText;

/**
 *  Sets the Custom Subtitle text to be shown on the Loading Screen. If not provided, default text will be shown.
 */
@property (nullable, nonatomic) NSString *loadingSubtitleText;


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
 *  Gets you the current theme themeConfig's semiBoldFont name. If you haven't set your custom themeConfig, it will return its default value.
 */
- (NSString *)semiBoldFont;

/**
 *  Gets you the current theme themeConfig's italicFont name. If you haven't set your custom themeConfig, it will return its default value.
 */
- (NSString *)italicFont;

/**
 *  Gets you the current tintColor of Navigation Items.
 */
- (UIColor *)navigationItemTintColor;


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
 
 @discussion
 The returned navigationController comes configured with the theming configurations.
 
 @code
 
 [[HPConfiguration shared] embeddInNavigationController:viewController];
 
 @endcode
 */
- (UINavigationController *)embeddInNavigationController:(__kindof UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
