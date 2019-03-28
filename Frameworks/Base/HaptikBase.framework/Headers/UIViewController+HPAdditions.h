//
//  UIViewController+HPAdditions.h
//  HaptikBase
//
//  Created by SimranJot Singh on 13/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (HPAdditions)

+ (UIViewController * )topViewController;

- (UIViewController * _Nullable)previousViewController;

@end

NS_ASSUME_NONNULL_END
