//
//  AppDelegate.swift
//  Swift-Example
//
//  Created by SimranJot Singh on 12/12/18.
//  Copyright © 2018 Simranjot. All rights reserved.
//

import UIKit
import HaptikLib

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // Required at the Initial Launch of the Application
        Haptik.sharedSDK().notify(application, launchedWithOptions: launchOptions)
        
        // Required for Enterprise Clients
        Haptik.sharedSDK().useInbox = false
        
        return true
    }

    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        
        // Let Haptik handle the redirect if required
        
        let isHandledByHaptik = Haptik.sharedSDK().isRedirectHandled(url, options: options)
        return isHandledByHaptik
    }

    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        
        // You need to pass the Device Token after the user successfully signs up in Haptik. Till that you need to store it in your application.
        
        UserDefaults.standard.set(deviceToken, forKey: "kDeviceToken")
        UserDefaults.standard.synchronize()
    }
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any]) {
        
        let isHaptikNotification = Haptik.sharedSDK().canHandleNotification(userInfo: userInfo as! [String : Any])
        
        if isHaptikNotification {
            
            print("Do Housekeeping")
            handleNotificationInteraction(userInfo as! [String : Any])
        }
    }
    
    func handleNotificationInteraction(_ userInfo: [String: Any]) {
        
        if let rootVC = self.window?.rootViewController {
            if let controller = rootVC as? UINavigationController {
                
                // You need to pass an instance of a viewController from which the user will be taken to the conversationViewController (where the user will be conversing)
                // on the tap of the Notification
                
                Haptik.sharedSDK().handleNotification(userInfo: userInfo, controller: controller.visibleViewController!)
            }
        }
    }
}

