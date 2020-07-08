//
//  RootViewController.swift
//  Swift-Example-Manual
//
//  Created by SimranJot Singh on 04/10/19.
//  Copyright © 2019 Haptik. All rights reserved.
//

import UIKit
import HaptikLib
import HaptikBase

class RootViewController: UIViewController {
    
    // MARK: Outlets & Attributes
    
    @IBOutlet weak var signupBtn: UIButton!
    @IBOutlet weak var loadingIndicator: UIActivityIndicatorView!
    
    let demoViaName = "sanqachannel"
    
    // MARK: Controller Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    
    // MARK: Actions
    
    @IBAction func openHaptikChat(_ sender: UIButton) {
        
        if Haptik.sharedSDK().isUserSignedUp() {
            
            triggerSignedUpFlow()
        }
        else {
            
            loadingIndicator.startAnimating()
            signupBtn.isHidden = loadingIndicator.isAnimating
            
            triggerSignInFlow {[unowned self] (conversation, error) in
                
                if let _ = error {
                    
                    // Handle error here ...
                    return;
                }
                
                self.setDeviceToken()
                
                if let conversation = conversation {
                    self.presentHaptikConversation(conversation)
                }
                
                self.loadingIndicator.stopAnimating()
                self.signupBtn.isHidden = self.loadingIndicator.isAnimating
            }
        }
    }
}


// MARK: Haptik Helper Extension

extension RootViewController {
    
    func triggerSignedUpFlow() {
        
        // Option A
        
        /*Haptik.sharedSDK().launchChannel(with: "channel_via_name",
         message: "any_message_you_wanna_start_With",
         controller: self);*/
        
        // Option B
        
        let conversation = try? Haptik.sharedSDK().getConversationFor(viaName: demoViaName,
                                                                      launchMessage: "",
                                                                      hideLaunchMessage: false)
        if let conversation = conversation {
            presentHaptikConversation(conversation)
        }
    }
    
    func triggerSignInFlow(completion: @escaping(_ conversation: UIViewController?, _ error: Error?) -> Void) {
        
        // Make the signup object which contains the required information used for signup
        let signupObject = HPSignUpObject.build(withAuthType: "basic") { (builder) in
            
            builder.userFullName = "DemoUser"
            builder.viaName = self.demoViaName
            
            // You can set more properties on the builder according to the requirements
        }
        
        Haptik.sharedSDK().signUp(with: signupObject) { (success, initialVC, error) in
            completion(initialVC, error);
        }
    }
    
    func presentHaptikConversation(_ conversationVC: UIViewController) {
        
        let navigationController = UINavigationController(rootViewController: conversationVC)
        
        HPConfiguration.shared().configureNavigationBarTintColor(UIColor(hexString: "#0050ddff"),
                                                                 navigationItemTintColor: .white,
                                                                 makeTranslucent: false,
                                                                 for: navigationController)
        
        present(navigationController, animated: true, completion: nil)
    }
    
    func setDeviceToken() {
        
        let deviceToken = UserDefaults.standard.object(forKey: "kDeviceToken") as? Data
        guard let token = deviceToken else { return }
        Haptik.sharedSDK().setDeviceToken(token)
    }
}

