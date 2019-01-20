//
//  SingleComponentPickerViewController.swift
//  Picker
//
//  Created by feihuihui on 2019/1/17.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class SingleComponentPickerViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return characterNames.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return characterNames[row]
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()

    }
    
    @IBOutlet weak var singlePicker: UIPickerView!
    private let characterNames = ["Zhang San", "Li Si", "Wang Wu", "Zhao Liu"]
    
    
    @IBAction func onButtonPressed(_ sender: UIButton) {
        let row = singlePicker.selectedRow(inComponent: 0)
        let selected = characterNames[row]
        let title = "\(selected) selected"
        
        let alert = UIAlertController(title: title, message: "thx", preferredStyle: .alert)
        let action = UIAlertAction(title: "you're welcome", style: .default, handler: nil)
        alert.addAction(action)
        present(alert, animated: true, completion: nil)
    }
    
}
