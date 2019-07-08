//
//  HPAudioAPI.h
//  HaptikBase
//
//  Created by SimranJot Singh on 02/05/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@protocol HPAudioAPI <NSObject>

/**
 @discussion
 A wrapper over AVAudioSessionRecordPermission representing the different permission states that for the HaptikAudio

 - HPRecordPermissionGranted: record permission granted by the user
 - HPRecordPermissionDenied: user denied access to the microphone
 - HPRecordPermissionUndetermined: record permission not yet authorized
 */
typedef NS_ENUM(NSUInteger, HPRecordPermissionStatus) {
    HPRecordPermissionGranted,
    HPRecordPermissionDenied,
    HPRecordPermissionUndetermined
};

@required


#pragma mark - Haptik Audio Authorization

/**
 @discussion
 Checks if the app is granted permission for recording by the user or not
 
 @return YES if the authorization status is HPRecordPermissionGranted else NO
 */
- (BOOL)isAuthorized;

/**
 @discussion
 Checks the current permission status for audio recording
 
 @return A HPRecordPermissionStatus case representing the current permission status
 */
- (HPRecordPermissionStatus)currentPermissionStatus;

/**
 @abstract
 Before starting the recording, you first have to ask for users permission to access the microphone
 
 @discussion
 Call this method to prompt the user for permission and handle their response in a completion block.
 
 @param completion Completion block called on users action to the prompt and will contain a bool telling if the user granted the access or denied it
 */
- (void)requestPermission:(void (^)(BOOL granted))completion;


#pragma mark - AudioSession Activation/Deactivation Helpers

/**
 Sets the AVAudioSessionCategory as "AVAudioSessionCategoryPlayAndRecord" on AVAudioSession's shared instance

 @return BOOL value representing the operations success
 */
- (BOOL)setupAudioSession;

/**
 Activates the AVAudioSession's shared instance with the option "AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation"

 @return BOOL value representing the operations success
 */
- (BOOL)activateSession;

/**
 Deactivates the AVAudioSession's shared instance with the option "AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation"

 @return BOOL value representing the operations success
 */
- (BOOL)deactivateSession;


#pragma mark - Text-to-Speech Queue Player Helpers

/**
 @discussion
 Appends the message to be streamed to the queue.

 @param message Text message to be spoken
 @return An indication of whether the message can be inserted into the queue/
 */
- (BOOL)insertTTSMessageToQueue:(NSString *)message;

/**
 @abstract
 Equivalent to setting the value of rate to 1.0.
 
 @discussion
 Signals the desire to begin playback at the queues current item's natural rate.
 */
- (void)play;

/**
 @abstract
 Equivalent to setting the value of rate to 0.0.
 
 @discussion
 Pauses playback.
 */
- (void)pause;

/**
 @abstract
 Removes all TTS items from the queue.
 
 @discussion
 Stops playback of the TTS items queue.
 */
- (void)clearTTSMessagesQueue;


@optional

/**
 @abstract
 Will provide delegate callback when the TTS Queue has finished playing all items
 
 @discussion
 Confirm to the "queueDelegate" object and get callback everytime the queue has finished playing all items
 */
- (void)queueFinishedPlayingEnqueuedItems;

@end

NS_ASSUME_NONNULL_END
