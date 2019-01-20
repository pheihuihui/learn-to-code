//
//  DatePickerViewController.swift
//  Picker
//
//  Created by feihuihui on 2019/1/17.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class DatePickerViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        let date = NSDate()
        datePicker.setDate(date as Date, animated: false)
    }
    
    @IBOutlet weak var datePicker: UIDatePicker!
    
    @IBAction func onButtonPressed(_ sender: UIButton) {
        let date = datePicker.date
        let message = "\(date) selected"
        let alert = UIAlertController(title: "date selected", message: message, preferredStyle: .alert)
        let action = UIAlertAction(title: "true", style: .default, handler: nil)
        alert.addAction(action)
        present(alert, animated: true, completion: nil)
    }
}
