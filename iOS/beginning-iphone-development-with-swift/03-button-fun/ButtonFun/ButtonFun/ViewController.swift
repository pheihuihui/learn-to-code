//
//  ViewController.swift
//  ButtonFun
//
//  Created by feihuihui on 2018/11/25.
//  Copyright © 2018 feihuihui. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    @IBAction func onButtonPressed(_ sender: UIButton) {
        let title = sender.title(for: .selected)!
        let text = "\(title) pressed"
        let styledText = NSMutableAttributedString(string: text)
        let attr = [
            NSAttributedString.Key.font: UIFont.boldSystemFont(ofSize: labelOutlet.font.pointSize)
        ]
        let nameRange = (text as NSString).range(of: title)
        styledText.setAttributes(attr, range: nameRange)
        labelOutlet.attributedText = styledText
    }
    
    @IBOutlet weak var labelOutlet: UILabel!
    
}

