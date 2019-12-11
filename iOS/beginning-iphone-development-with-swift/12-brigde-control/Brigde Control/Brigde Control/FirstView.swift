//
//  FirstView.swift
//  Brigde Control
//
//  Created by feihuihui on 2019/10/4.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import SwiftUI
import Foundation

struct FirstView: View {
    @State private var defaults = UserDefaults.standard
    
    var body: some View {
        VStack{
            HStack{
                Text("Favorite Tea: ")
                Spacer()
                Text("\(defaults.string(forKey: favoriteTeaKey) ?? "None")")
                }.padding(.horizontal, 20)
            HStack{
                Text("Warp Drive: ")
                Spacer()
                Text("\(defaults.bool(forKey: warpDriveKey) ? "Enabled" : "Disabled")")
            }.padding(.horizontal, 20)
            if defaults.bool(forKey: warpDriveKey){
                Text("warp drive enabled")
            }
        }
    }
}

struct FirstView_Previews: PreviewProvider {
    static var previews: some View {
        FirstView()
    }
}
