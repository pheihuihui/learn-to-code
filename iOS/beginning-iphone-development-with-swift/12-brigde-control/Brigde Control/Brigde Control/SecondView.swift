//
//  SecondView.swift
//  Brigde Control
//
//  Created by feihuihui on 2019/10/4.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import SwiftUI

struct SecondView: View {
    @State private var defaults = UserDefaults.standard
    @State private var resultString = ""
    var body: some View {
        VStack{
            Button(action: {
                let app = UIApplication.shared
                let url = URL(string: UIApplication.openSettingsURLString)! as URL
                if app.canOpenURL(url){
                    app.open(url, options: [:], completionHandler: nil)
                }
            }){
                Text("Settings")
            }
            
            Button(action: {
                self.resultString = self.defaults.bool(forKey: warpDriveKey) ? "Enabled" : "Disabled"
            }){
                Text("Show settings")
            }
            
            Text("\(resultString == "" ? "Empty" : resultString)")
        }
    }
}

struct SecondView_Previews: PreviewProvider {
    static var previews: some View {
        SecondView()
    }
}
