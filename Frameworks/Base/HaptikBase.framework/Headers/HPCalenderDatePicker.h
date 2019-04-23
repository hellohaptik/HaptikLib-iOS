//
//  HPCalenderDatePicker.h
//  Haptik
//
//  Created by Rajesh Maurya on 8/17/16.
//  Copyright © 2016 Haptik Inc. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface HPCalenderDatePicker : UIView

+ (void)presentCalenderDatePickerWithStartDate:(nullable NSDate *)startDate
                                       endDate:(nullable NSDate *)endDate
                                  selectedDate:(nullable NSDate *)selectedDate
                                     textField:(id)textField
                                    completion:(void(^)(NSDate *date))completion;

@end

NS_ASSUME_NONNULL_END
