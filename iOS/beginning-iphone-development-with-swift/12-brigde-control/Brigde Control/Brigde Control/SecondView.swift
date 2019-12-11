//
//  SecondView.swift
//  Brigde Control
//
//  Created by feihuihui on 2019/10/4.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import SwiftUI

struct SecondView: View {
    private var defaults = UserDefaults.standard
    @State private var resultString = ""
    @State private var switchOn = false
    
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
            
            Toggle(isOn: $switchOn) {
                Text("Warp Drive: ")
            }.padding(.horizontal, 20)
            
            HStack{
                Text("Toggle State: ")
                Spacer()
                Text("\(switchOn ? "On" : "Off")")
            }.padding(.horizontal, 20)
            
            Button(action: {
                self.resultString = self.defaults.bool(forKey: warpDriveKey) ? "Enabled" : "Disabled"
            }){
                Text("Show settings")
            }
            
            Text("\(resultString == "" ? "Empty" : resultString)")
        }.onAppear {
            self.switchOn = self.defaults.bool(forKey: warpDriveKey)
        }
    }
}

struct SecondView_Previews: PreviewProvider {
    static var previews: some View {
        SecondView()
    }
}
