//
//  DoubleComponentPickerViewController.swift
//  Picker
//
//  Created by feihuihui on 2019/1/17.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class DoubleComponentPickerViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 2
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        if component == breadComponent {
            return breadTypes.count
        } else {
            return fillingTypes.count
        }
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        if component == breadComponent {
            return breadTypes[row]
        } else {
            return fillingTypes[row]
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

    }
    
    @IBOutlet weak var doublePicker: UIPickerView!
    
    @IBAction func onButtonPressed(_ sender: UIButton) {
        let fillingRow = doublePicker.selectedRow(inComponent: fillingComponent)
        let breadRow = doublePicker.selectedRow(inComponent: breadComponent)
        let filling = fillingTypes[fillingRow]
        let bread = breadTypes[breadRow]
        let message = "\(filling) and \(bread)"
        let alert = UIAlertController(title: "date selected", message: message, preferredStyle: .alert)
        let action = UIAlertAction(title: "true", style: .default, handler: nil)
        alert.addAction(action)
        present(alert, animated: true, completion: nil)
    }
    
    private let fillingComponent = 0
    private let breadComponent = 1
    private let fillingTypes = ["Tom", "Jack", "Mike", "Joe"]
    private let breadTypes = ["Zhao", "Qian", "Sun", "Li"]
    
    
}
