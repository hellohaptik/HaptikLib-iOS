//
//  NSFileManager+HPAdditions.h
//  HaptikBase
//
//  Created by SimranJot Singh on 16/07/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSFileManager (HPAdditions)

/**
 Gets the URL of the Documents directory of the app.
 
 @return Documents directory URL.
 */
+ (NSURL *)hp_documentsDirectoryURL;

/**
 Gets the path of the Documents directory of the app.
 
 @return Documents directory path.
 */
+ (NSString *)hp_documentsDirectoryPath;

/**
 Gets the URL of the Library directory of the app.
 
 @return Library directory URL.
 */
+ (NSURL *)hp_libraryDirectoryURL;

/**
 Gets the path of the Library directory of the app.
 
 @return Library directory path.
 */
+ (NSString *)hp_libraryDirectoryPath;

/**
 Gets the URL of the Caches directory of the app.
 
 @return Caches directory URL.
 */
+ (NSURL *)hp_cachesDirectoryURL;

/**
 Gets the path of the Caches directory of the app.
 
 @return Caches directory path.
 */
+ (NSString *)hp_cachesDirectoryPath;

/**
 Adds a special filesystem flag to a file to avoid iCloud backup it.
 
 @param path Path to a file to set an attribute.
 */
+ (BOOL)hp_addSkipBackupAttributeToFile:(NSString *)path;

/**
 Get available disk space.
 
 @return An amount of available disk space in Megabytes.
 */
+ (double)hp_availableDiskSpace;

@end

NS_ASSUME_NONNULL_END
