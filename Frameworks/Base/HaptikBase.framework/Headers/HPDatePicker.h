//
//  HPDatePicker.h
//  HaptikBase
//
//  Created by SimranJot Singh on 08/03/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface HPDatePicker : NSObject

typedef void(^ _Nullable HPDatePickerDoneBlock)(id selectedDate, id origin);
typedef void(^ _Nullable HPDatePickerCancelBlock)(void);

+ (void)showDatePickerWithTitle:(NSString *)title
                 datePickerMode:(UIDatePickerMode)datePickerMode
                   selectedDate:(NSDate * )selectedDate
                    minimumDate:(NSDate * _Nullable)minimumDate
                    maximumDate:(NSDate * _Nullable)maximumDate
                         origin:(UIView *)originView
                      doneBlock:(HPDatePickerDoneBlock)doneBlock
                    cancelBlock:(HPDatePickerCancelBlock)cancelBlock;

@end

NS_ASSUME_NONNULL_END
