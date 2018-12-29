//
//  ViewController.swift
//  Control Fun
//
//  Created by feihuihui on 2018/12/1.
//  Copyright © 2018 feihuihui. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var numberField: UITextField!
    @IBOutlet weak var sliderLabel: UILabel!
    @IBOutlet weak var mySlider: UISlider!
    @IBOutlet weak var leftSwitch: UISwitch!
    @IBOutlet weak var rightSwitch: UISwitch!
    @IBOutlet weak var doSthButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        sliderLabel.text = "\(lroundf(mySlider.value))"
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    @IBAction func textFieldDoneEditing(sender: UITextField){
        sender.resignFirstResponder()
    }
    
    @IBAction func onTapGestureRecognized(_ sender: AnyObject) {
        nameField.resignFirstResponder()
        numberField.resignFirstResponder()
    }
    
    @IBAction func sliderChanged(_ sender: UISlider) {
        sliderLabel.text = "\(lroundf(sender.value))"
    }
    
    @IBAction func onSwitchChanged(_ sender: UISwitch) {
        let setting = sender.isOn
        leftSwitch.setOn(setting, animated: true)
        rightSwitch.setOn(setting, animated: false)
    }
    
    @IBAction func toggleControls(_ sender: UISegmentedControl) {
        if sender.selectedSegmentIndex == 0 {
            leftSwitch.isHidden = false
            rightSwitch.isHidden = false
            doSthButton.isHidden = true
        } else {
            leftSwitch.isHidden = true
            rightSwitch.isHidden = true
            doSthButton.isHidden = false
        }
    }
    
    @IBAction func onButtonPressed(_ sender: UIButton) {
        let controller = UIAlertController(title: "Are you sure?", message: nil, preferredStyle: .actionSheet)
        let yesAction = UIAlertAction(title: "Yes", style: .destructive, handler: {action in
            let msg = self.nameField.text!.isEmpty ? "OK." : "\(self.nameField.text!), OK."
            let controller2 = UIAlertController(title: "Done.", message: msg, preferredStyle: .alert)
            let cancelAction = UIAlertAction(title: "Phew!", style: .cancel, handler: nil)
            controller2.addAction(cancelAction)
            self.present(controller2, animated: true, completion: nil)
        })
        let noAction = UIAlertAction(title: "No way", style: .cancel, handler: nil)
        controller.addAction(yesAction)
        controller.addAction(noAction)
        if let ppc = controller.popoverPresentationController {
            ppc.sourceView = sender
            ppc.sourceRect = sender.bounds
        }
        present(controller, animated: true, completion: nil)
    }
}

