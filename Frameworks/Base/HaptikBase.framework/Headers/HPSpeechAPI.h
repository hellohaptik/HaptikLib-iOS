//
//  HPSpeechAPI.h
//  HaptikBase
//
//  Created by SimranJot Singh on 17/04/19.
//  Copyright © 2019 Haptik. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@protocol HPSpeechAPI <NSObject>

/**
 @discussion
 A wrapper over SFSpeechRecognizerAuthorizationStatus representing the different authorization states that for the HaptikSpeech
 
 - HPSpeechRecognizerAuthorizationStatusNotDetermined: Speech recognition not yet authorized
 - HPSpeechRecognizerAuthorizationStatusDenied: Access to speech recognition is denied by the user
 - HPSpeechRecognizerAuthorizationStatusRestricted: Speech recognition restricted on this device
 - HPSpeechRecognizerAuthorizationStatusAuthorized: User gave access for speech recognition
 */
typedef NS_ENUM(NSInteger, HPSpeechRecognizerAuthorizationStatus) {
    HPSpeechRecognizerAuthorizationStatusNotDetermined,
    HPSpeechRecognizerAuthorizationStatusDenied,
    HPSpeechRecognizerAuthorizationStatusRestricted,
    HPSpeechRecognizerAuthorizationStatusAuthorized,
};

@required


#pragma mark - Haptik Speech Authorization

/**
 @discussion
 Checks if the app is authorized for speech recognition by the user or not
 
 @return YES if the authorization status is HPSpeechRecognizerAuthorizationStatusAuthorized else NO
 */
- (BOOL)isAuthorized;

/**
 @discussion
 Checks the current authorization status for speech recognition
 
 @return A HPSpeechRecognizerAuthorizationStatus case representing the current authorization status
 */
- (HPSpeechRecognizerAuthorizationStatus)currentAuthorizationStatus;

/**
 @abstract
 Before using the speech recognition, you have to first ask for users permission because the recognition doesn’t happen just locally on the iOS device but Apple’s servers.
 All the voice data is transmitted to Apple’s backend for processing. Therefore, it is mandatory to get the user’s authorization.
 
 @discussion
 Call this method to prompt the user for authorization and handle their response in a completion block.
 
 @param completion Completion block called on users action to the prompt and will containing the authorization status representing for the same
 */
- (void)requestAuthorization:(void (^)(HPSpeechRecognizerAuthorizationStatus status))completion;


#pragma mark - Haptik Speech Recognition Tasks

/**
 @discussion
 Calling this method will preallocates many of the resources the audio engine requires and will start the recognition for the users current set locale.
 You must activate the audioSession before utilizing this method.
 
 @param resultHandler Result block called multiple times containing the:
 
 "bestMatch" formatted string that it keeps recognizing
 "isFinal" is set to YES if the bestMatch string is the final recognized string and a nullable
 "error" which can contain error throwed by the Apple's Speech Framework while recognizing the feeded audio
 
 @return BOOL value indicating if the AudioEngine for recording the users voice was able to start or not. Speech detection will not happen if the AudioEngine is not able to start
 */
- (BOOL)startRecognitionTask:(void (^)(NSString * _Nonnull bestMatch, BOOL isFinal, NSError * _Nullable error))resultHandler;


/**
 Tells whether the recognition task is running or not

 @return YES if the recognition task is on going else NO
 */
- (BOOL)isRecognitionRunning;

/**
 Stops the activity of recording the users voice and recognozing it. After that it sends the final callback.
 */
- (void)finishRecognition;

/**
 You can call it in any error or dismissal scenario. You should also call this method when the user swithces to background state while recording his audio.
 */
- (void)cancelRecognition;

@end

NS_ASSUME_NONNULL_END


