//
//  AppDelegate.swift
//  Swift-Example
//
//  Created by SimranJot Singh on 12/12/18.
//  Copyright © 2018 Simranjot. All rights reserved.
//

import UIKit
import HaptikLib
import HaptikBase
import UserNotifications;

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // If you need the callbacks of the analytics data that haptik sends
        HPConfiguration.shared().analyticsCallbackObject = self;
        
        // If you don't need the mic button
        HPConfiguration.shared().useVoice = false;
        
        // Setup UI Theme for Haptik
        setHaptikTheme()
        
        return true
    }    
}


// MARK: Notification Helpers

extension AppDelegate {
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        
        // You need to pass the Device Token after the user successfully signs up in Haptik. Till that you need to store it in your application.
        
        UserDefaults.standard.set(deviceToken, forKey: "kDeviceToken")
        UserDefaults.standard.synchronize()
        
        Haptik.sharedSDK().setDeviceToken(deviceToken)
    }
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any]) {
        
        // Check if the notification received belongs to haptik and take action accordingly
        
        let isHaptikNotification = Haptik.sharedSDK().canHandleNotification(userInfo: userInfo as! [String : Any])
        
        if isHaptikNotification {
            
            print("Do Housekeeping")
            handleNotificationInteraction(userInfo as! [String : Any])
        }
    }
    
    @available(iOS 10.0, *)
    func userNotificationCenter(_ center: UNUserNotificationCenter,
                                didReceive response: UNNotificationResponse,
                                withCompletionHandler completionHandler: @escaping () -> Void) {

        // Check if the notification received belongs to haptik and take action accordingly

        let userInfo = response.notification.request.content.userInfo as! [String : Any]
        let isHaptikNotification = Haptik.sharedSDK().canHandleNotification(userInfo: userInfo)

        if isHaptikNotification {

            print("Do Housekeeping")
            handleNotificationInteraction(userInfo)
        }
    }
}


//MARK: Helper Methods

extension AppDelegate {
    
    func handleNotificationInteraction(_ userInfo: [String: Any]) {
        
        if let rootVC = self.window?.rootViewController {
            if let controller = rootVC as? UINavigationController {
                
                // You need to pass an instance of a viewController from which the user will be taken to the conversationViewController (where the user will be conversing)
                // on the tap of the Notification                
                Haptik.sharedSDK().didReceiveRemoteNotification(userInfo, controller: controller.visibleViewController!)
                
            }
        }
    }
    
    func setHaptikTheme() {
        
        // NOTE: Haptik only gives instances of viewControllers. When you push them on your stack, the navigationBar is still the yours, hence it's appearance too.
        
        // The following there configuration is the default configuration. If you don't provide one then the SDK will try to adopt the following.
        
        HPConfiguration.shared().themeConfig = HPThemeService.build { (builder) in
            
            builder?.brandColor = UIColor(hexString: "#0050ddff")
            builder?.businessChatBackground = UIColor(hexString: "#f0f0f0ff")
            builder?.businessChatText = UIColor(hexString: "#333333ff")
            builder?.messageTimeStamp = UIColor(hexString: "#777777ff")
            
            builder?.lightFont = "HelveticaNeue-Light"
            builder?.regularFont = "HelveticaNeue"
            builder?.mediumFont = "HelveticaNeue-Medium"
            builder?.boldFont = "HelveticaNeue-Bold"
            builder?.italicFont = "HelveticaNeue-Italic"
        }
    }
}


// MARK: - HPAnalytics Service Delegates

extension AppDelegate: HPAnalyticsServiceDelegate {
    
    func eventTracked(_ eventName: String, forParams params: [AnyHashable : Any]?) {
     
        // Get all the events tracked here
    }
}

