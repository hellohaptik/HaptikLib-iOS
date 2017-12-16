//
//  Tasks+CoreDataClass.h
//  HaptikLib
//
//  Created by SimranJot Singh on 05/10/17.
//  Copyright © 2017 Haptik. All rights reserved.
//
//


@import CoreData;

@class Business, Forms;

NS_ASSUME_NONNULL_BEGIN

@interface Tasks : NSManagedObject

+ (Tasks *)getTaskEntityForObjectID:(NSNumber *)objectID
                         businessID:(NSNumber *)businessID
                            context:(NSManagedObjectContext *)context;


+ (NSFetchRequest<Tasks *> *)getValidTasksFor:(NSNumber *)businessID;

@end

NS_ASSUME_NONNULL_END

#import "Tasks+CoreDataProperties.h"

