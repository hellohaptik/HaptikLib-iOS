---
title: Native Communications Bridge
---

HaptikLib has the ability to communicate with the parent application for data exchange during the bot conversations to get more context. The `HPConfiguration` class exposes a delegate attribute of `HPMessagingListenerAPI` type:

```
@property (nullable, nonatomic, weak) id <HPMessagingListenerAPI> messagingListenerObject;
```

If the object is confirmed by any class, the SDK will try to ask for some data needed during the chatbot conversation with the user from the application through the methods provided in the `HPMessagingListenerAPI`. It has the following requied method that the application has to confirm by setting the `messagingListenerObject` delegate object.

```

/**
 If the clients application confirms to the `messagingListenerObject` of HPConfiguration, the SDK will fire these methods through the confirmed object to get some data from the application for updating data in the chat flow.

 @discussion
 The contracts for the `actionType` and the `resultsDict` needs to be pre-decided by both the parties before.

 @param actionType telling which action to be trigerred by the application
 @param actionParams Parameters required to perform the operation
 @param resultHandler The result passed by the application to the SDK after the action is performed. This can be called multiple times too.
 */
- (void)performAppActionFor:(NSString *)actionType
               actionParams:(NSArray<NSString *> *)actionParams
              resultHandler:(void (^)(NSDictionary * _Nonnull resultsDict))resultHandler;

```

---