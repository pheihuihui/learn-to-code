//
//  ViewController.swift
//  Vocabulario
//
//  Created by feihuihui on 2018/11/14.
//  Copyright © 2018 feihuihui. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var textField: UITextField!
    var startNum: Int = Int.max - 10
    @IBAction func buttonTap(_ sender: UIButton) {
        startNum += 1
        textField.text = String(startNum)
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        textField.text = String(startNum)
    }
    
}

