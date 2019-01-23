//
//  ViewController.swift
//  Simple Table
//
//  Created by feihuihui on 2019/1/22.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource {
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return keys.count
    }
    
    func sectionIndexTitles(for tableView: UITableView) -> [String]? {
        return keys
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        let key = keys[section]
        let nameSection = names[key]!
        return nameSection.count
    }
    
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return keys[section]
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: sectionsTableIdentifier, for: indexPath) as UITableViewCell
        let key = keys[indexPath.section]
        let nameSection = names[key]!
        cell.textLabel!.text = nameSection[indexPath.row]
        return cell
    }
    
    
    let sectionsTableIdentifier = "SectionsTableIdentifier"
    var names: [String: [String]]!
    var keys: [String]!
    @IBOutlet weak var tableView: UITableView!
    var searchController: UISearchController!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: sectionsTableIdentifier)
        let path = Bundle.main.path(forResource: "sortednames", ofType: "plist")
        let namesDic = NSDictionary(contentsOfFile: path!)
        names = namesDic as? [String: [String]]
        keys = (namesDic!.allKeys as! [String]).sorted()
        
        let resultsController = SearchResultsController()
        resultsController.names = names
        resultsController.keys = keys
        searchController = UISearchController(searchResultsController: resultsController)
        let searchBar = searchController.searchBar
        searchBar.scopeButtonTitles = ["All", "Short", "Long"]
        searchBar.placeholder = "Enter key words"
        searchBar.sizeToFit()
        tableView.tableHeaderView = searchBar
        searchController.searchResultsUpdater = resultsController
    }
    
    
    
//    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
//        return computers.count
//    }
//
//    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
//        var cell = tableView.dequeueReusableCell(withIdentifier: simpleTableIdentifier)
//        if cell == nil {
//            cell = UITableViewCell(style: .subtitle, reuseIdentifier: simpleTableIdentifier)
//        }
//        let img = UIImage(named: "star")
//        cell?.imageView?.image = img
//        let himg = UIImage(named: "hstar")
//        cell?.imageView?.highlightedImage = himg
//        cell?.textLabel?.text = dwarves[indexPath.row]
//        cell?.detailTextLabel?.text = "No. \(indexPath)"
//        return cell!
//    }
//
//    private let dwarves = ["Sleepy", "Sneezy", "Bashful", "Happy", "Doc"]
//    let simpleTableIdentifier = "SimpleTableIdentifier"
    
//    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
//        let cell = tableView.dequeueReusableCell(withIdentifier: cellTableIdentifier, for: indexPath) as! NameAndColorCell
//        let rowData = computers[indexPath.row]
//        cell.name = rowData["Name"]!
//        cell.color = rowData["Color"]!
//
//        return cell
//    }
//
//    let cellTableIdentifier = "CellTableIdentifier"
//    @IBOutlet var tableView: UITableView!
//    let computers = [
//        ["Name": "macbook air", "Color": "silver"],
//        ["Name": "surface book", "Color": "blue"],
//        ["Name": "chrome book", "Color": "yellow"]
//    ]
//
//    override func viewDidLoad() {
//        super.viewDidLoad()
//        tableView.register(NameAndColorCell.self, forCellReuseIdentifier: cellTableIdentifier)
//        let xib = UINib(nibName: "NameAndColorCell", bundle: nil)
//        tableView.register(xib, forCellReuseIdentifier: cellTableIdentifier)
//        tableView.rowHeight = 90
//    }


}

