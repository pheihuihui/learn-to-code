//
//  YellowViewController.swift
//  SwtchingViewApp
//
//  Created by feihuihui on 2019/1/14.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class YellowViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    @IBAction func yellowButtonPressed(sender: UIButton) {
        let alert = UIAlertController(title: "yellow button pressed", message: "you pressed yellow", preferredStyle: .alert)
        let action = UIAlertAction(title: "yes i did", style: .default, handler: nil)
        alert.addAction(action)
        present(alert, animated: true, completion: nil)
    }

}
