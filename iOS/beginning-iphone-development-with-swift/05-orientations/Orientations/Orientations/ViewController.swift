//
//  ViewController.swift
//  Orientations
//
//  Created by feihuihui on 2019/1/6.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        get {
            return UIInterfaceOrientationMask(
                rawValue: (
                    UIInterfaceOrientationMask.portrait.rawValue |
                    UIInterfaceOrientationMask.landscapeLeft.rawValue |
                    UIInterfaceOrientationMask.landscapeRight.rawValue
            ))
        }
    }
}

