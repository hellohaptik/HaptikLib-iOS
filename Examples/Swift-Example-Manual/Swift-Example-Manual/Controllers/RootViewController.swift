//
//  RootViewController.swift
//  Swift-Example-Manual
//
//  Created by SimranJot Singh on 04/10/19.
//  Copyright © 2019 Haptik. All rights reserved.
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
            
            // NOTE: For Publishers:
            // initialVC gives a list of channels that are available to that client
            
            // Haptik.sharedSDK().getInitialVC() gives you the initialVC that you can push on your stack
            
            // NOTE: For Enterprise:
            // You don't need to push to the initialVC that Haptik gives. You need to directly go to the conversation channel with the "viaName" that will be provided to you.
            // You can use:
            
            /*Haptik.sharedSDK().launchChannel(with: "provided_via_name",
             message: "any_message_you_wanna_start_With",
             controller: <#instance_of_vc_from_which_the_conversationVC_is_pushed#>)*/
        }
        else {
            
            loadingIndicator.startAnimating()
            signupBtn.isHidden = loadingIndicator.isAnimating
            
            let signupObject = HPSignUpObject.build(withAuthType: "basic") { (builder) in
                
                builder.userFullName = "Simranjot"
                
                // You can set more properties on the builder according to the requirements
            }
            
            Haptik.sharedSDK().signUp(with: signupObject) { [unowned self] (success, initialVC, error) in
                
                if success {
                    
                    // From here you can either push to the specific conversation controller or to the list of channel controller according to your requirements
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

