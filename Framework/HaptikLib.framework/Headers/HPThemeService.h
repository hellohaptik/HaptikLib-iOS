//
//  HPThemeService.h
//  HaptikLib
//
//  Created by SimranJot Singh on 22/11/17.
//  Copyright © 2017 Haptik. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HPThemeServiceBuilder;

NS_ASSUME_NONNULL_BEGIN

@interface HPThemeService : NSObject

/*
 *  Color Variables
 */

@property (nonatomic) UIColor *brandColor;

@property (nonatomic) UIColor *businessChatBackground;

@property (nonatomic) UIColor *businessChatText;

@property (nonatomic) UIColor *messageTimeStamp;


/*
 *  Typography Variables
 */

@property (nonatomic) NSString *lightFont;

@property (nonatomic) NSString *regularFont;

@property (nonatomic) NSString *mediumFont;


/*
 *  A class method which builds the "HPThemeServiceBuilder" object and initalizes your "HPThemeService" object with the data provided.
 *  @param builderData : The builder data provided in the block.
 */

+ (instancetype)buildWithData:(void (^ _Nullable)(HPThemeServiceBuilder * _Nullable builder))builderData;

@end

NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN

@interface HPThemeServiceBuilder : NSObject

@property (nonatomic) UIColor *brandColor;

@property (nonatomic) UIColor *businessChatBackground;

@property (nonatomic) UIColor *businessChatText;

@property (nonatomic) UIColor *messageTimeStamp;

@property (nonatomic) NSString *lightFont;

@property (nonatomic) NSString *regularFont;

@property (nonatomic) NSString *mediumFont;

- (HPThemeService *)build;

@end

NS_ASSUME_NONNULL_END

