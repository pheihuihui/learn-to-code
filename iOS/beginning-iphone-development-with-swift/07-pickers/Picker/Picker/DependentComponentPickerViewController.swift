//
//  DependentComponentPickerViewController.swift
//  Picker
//
//  Created by feihuihui on 2019/1/17.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class DependentComponentPickerViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    
    @IBOutlet weak var dependentPicker: UIPickerView!
    
    private let typesComponent = 0
    private let contentsComponent = 1
    private var typesContents: [String : [String]]!
    private var types: [String]!
    private var contents: [String]!
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 2
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        if component == typesComponent {
            return types.count
        } else {
            return contents.count
        }
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        if component == typesComponent {
            return types[row]
        } else {
            return contents[row]
        }
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        if component == typesComponent {
            let selecedType = types[row]
            contents = typesContents[selecedType]
            dependentPicker.reloadComponent(contentsComponent)
            dependentPicker.selectRow(0, inComponent: contentsComponent, animated: true)
        }
    }
    

    override func viewDidLoad() {
        super.viewDidLoad()
        typesContents = [String : [String]]()
        typesContents["Games"] = ["overwatch", "warcraft", "dark douls"]
        typesContents["Movies"] = ["interstellar", "the dark knight", "the matrix"]
        types = typesContents.keys.sorted()
        contents = typesContents[types[0]]
    }
    
    @IBAction func onButtonPressed(_ sender: UIButton) {
        let typesRow = dependentPicker.selectedRow(inComponent: typesComponent)
        let contentsRow = dependentPicker.selectedRow(inComponent: contentsComponent)
        let type = types[typesRow]
        let content = contents[contentsRow]
        let title = "\(type) selected"
        let message = "\(content) in \(type)"
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        let action = UIAlertAction(title: "true", style: .default, handler: nil)
        alert.addAction(action)
        present(alert, animated: true, completion: nil)
    }
    
}
