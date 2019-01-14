//
//  ViewController.swift
//  SwtchingViewApp
//
//  Created by feihuihui on 2019/1/14.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    private var blueViewController: BlueViewController!
    private var yellowViewController: YellowViewController!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        blueViewController = storyboard?.instantiateViewController(withIdentifier: "Blue") as? BlueViewController
        blueViewController.view.frame = view.frame
        switchViewController(from: nil, to: blueViewController)
    }
    
    @IBAction func switchVeiws(sender: UIBarButtonItem) {
        if yellowViewController?.view.superview == nil {
            if yellowViewController == nil {
                yellowViewController = storyboard?.instantiateViewController(withIdentifier: "Yellow") as? YellowViewController
            } else if blueViewController?.view.superview == nil {
                if blueViewController == nil {
                    blueViewController = storyboard?.instantiateViewController(withIdentifier: "Blue") as? BlueViewController
                }
            }
        }
        
        UIView.beginAnimations("View Flip", context: nil)
        UIView.setAnimationDuration(1)
        UIView.setAnimationCurve(.easeInOut)
        
        if blueViewController != nil && blueViewController!.view.superview != nil {
            UIView.setAnimationTransition(.flipFromLeft, for: view, cache: true)
            yellowViewController.view.frame = view.frame
            switchViewController(from: blueViewController, to: yellowViewController)
        } else {
            UIView.setAnimationTransition(.flipFromRight, for: view, cache: true)
            blueViewController.view.frame = view.frame
            switchViewController(from: yellowViewController, to: blueViewController)
        }
        UIView.commitAnimations()
    }
    
    private func switchViewController(from fromVC: UIViewController?, to toVC: UIViewController?) {
        if fromVC != nil {
            fromVC!.willMove(toParent: nil)
            fromVC!.view.removeFromSuperview()
            fromVC!.removeFromParent()
        }
        if toVC != nil {
            self.addChild(toVC!)
            self.view.insertSubview(toVC!.view, at: 0)
            toVC!.didMove(toParent: self)
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        if blueViewController != nil && blueViewController!.view.superview == nil {
            blueViewController = nil
        }
        if yellowViewController != nil && yellowViewController!.view.superview == nil {
            yellowViewController = nil
        }
    }


}

