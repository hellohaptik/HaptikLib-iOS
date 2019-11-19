//
//  RootViewController.swift
//  Swift-Example
//
//  Created by SimranJot Singh on 12/12/18.
//  Copyright © 2018 Simranjot. All rights reserved.
//

import UIKit
import HaptikLib

class RootViewController: UIViewController {

    // MARK: Outlets & Attributes
    
    @IBOutlet weak var signupBtn: UIButton!
    @IBOutlet weak var loadingIndicator: UIActivityIndicatorView!
    
    
    // MARK: Controller Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    
    // MARK: Actions
    
    @IBAction func signupTapped(_ sender: UIButton) {
        
        if Haptik.sharedSDK().isUserSignedUp() {
            
            // Option A
            
            /*Haptik.sharedSDK().launchChannel(with: "channel_via_name",
                                             message: "any_message_you_wanna_start_With",
                                             controller: self);*/
            
            // Option B
            
            let conversation = try? Haptik.sharedSDK().getConversationFor(viaName: "channel_via_name")
            if let conversation = conversation {
                present(conversation, animated: true, completion: nil)
            }
        }
        else {
            
            loadingIndicator.startAnimating()
            signupBtn.isHidden = loadingIndicator.isAnimating
            
            let signupObject = HPSignUpObject.build(withAuthType: "basic") { (builder) in
                
                builder.userFullName = "Simranjot"
                builder.viaName = "channel_via_name"
                
                // You can set more properties on the builder according to the requirements
            }
            
            Haptik.sharedSDK().signUp(with: signupObject) { [unowned self] (success, initialVC, error) in
                
                if success {
                    
                    // From here you can either push to the specific conversation controller if you pass in the via name in the builder
                    
                    if let initialVC = initialVC {
                        self.present(initialVC, animated: true, completion: nil)
                    }
                    else {
                        // Handle Error here
                    }
                }
                else {
                    
                    // Handle Error here
                }
                
                self.loadingIndicator.stopAnimating()
                self.signupBtn.isHidden = self.loadingIndicator.isAnimating
            }
        }
    }
}

