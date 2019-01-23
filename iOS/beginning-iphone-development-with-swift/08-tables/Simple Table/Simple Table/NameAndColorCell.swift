//
//  NameAndColorCell.swift
//  Simple Table
//
//  Created by feihuihui on 2019/1/22.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class NameAndColorCell: UITableViewCell {
    
    var name: String = "" {
        didSet {
            if name != oldValue {
                nameLabel.text = name
            }
        }
    }
    var color: String = "" {
        didSet {
            if color != oldValue {
                colorLabel.text = color
            }
        }
    }
    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var colorLabel: UILabel!
    
//    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
//        super.init(style: style, reuseIdentifier: reuseIdentifier)
//
//        let nameLabelRect = CGRect(x: 0, y: 5, width: 70, height: 15)
//        let nameMaker = UILabel(frame: nameLabelRect)
//        nameMaker.textAlignment = NSTextAlignment.right
//        nameMaker.text = "Name: "
//        nameMaker.font = UIFont.boldSystemFont(ofSize: 12)
//        contentView.addSubview(nameMaker)
//
//        let colorLabelRect = CGRect(x: 0, y: 26, width: 70, height: 15)
//        let colorMaker = UILabel(frame: colorLabelRect)
//        colorMaker.textAlignment = NSTextAlignment.right
//        colorMaker.text = "Color: "
//        colorMaker.font = UIFont.boldSystemFont(ofSize: 12)
//        contentView.addSubview(colorMaker)
//
//        let nameValueRect = CGRect(x: 80, y: 5, width: 200, height: 15)
//        nameLabel = UILabel(frame: nameValueRect)
//        contentView.addSubview(nameLabel)
//
//        let colorValueRect = CGRect(x: 80, y: 25, width: 200, height: 15)
//        colorLabel = UILabel(frame: colorValueRect)
//        contentView.addSubview(colorLabel)
//    }
//
//    required init?(coder aDecoder: NSCoder) {
//        fatalError("Not implemented")
//    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
