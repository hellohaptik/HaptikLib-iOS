//
//  HPStringPicker.h
//  HaptikBase
//
//  Created by SimranJot Singh on 08/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface HPStringPicker : NSObject

typedef void(^ _Nullable HPStringPickerDoneBlock)(NSInteger selectedIndex, id selectedValue);
typedef void(^ _Nullable HPStringPickerCancelBlock)(void);

+ (void)showStringPickerWithTitle:(NSString *)title
                         rowItems:(NSArray *)rowItems
                 initialSelection:(NSInteger)initialSelectionIndex
                       originView:(id)originView
                        doneBlock:(HPStringPickerDoneBlock)doneBlock
                      cancelBlock:(HPStringPickerCancelBlock)cancelBlock;

@end

NS_ASSUME_NONNULL_END
