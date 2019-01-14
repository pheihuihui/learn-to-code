//
//  BlueViewController.swift
//  SwtchingViewApp
//
//  Created by feihuihui on 2019/1/14.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class BlueViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
    

    @IBAction func blueButtonPressed(sender: UIButton) {
        let alert = UIAlertController(title: "blue button pressed", message: "you pressed blue", preferredStyle: .alert)
        let action = UIAlertAction(title: "yes i did", style: .default, handler: nil)
        alert.addAction(action)
        present(alert, animated: true, completion: nil)
    }

}
