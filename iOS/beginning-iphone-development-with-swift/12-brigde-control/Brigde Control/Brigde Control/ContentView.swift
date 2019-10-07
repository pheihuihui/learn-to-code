//
//  ContentView.swift
//  Brigde Control
//
//  Created by feihuihui on 2019/10/3.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        TabView{
            FirstView().tabItem{
                Image(systemName: "1.circle")
                Text("first view")
            }
            SecondView().tabItem{
                Image(systemName: "2.circle")
                Text("second view")
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
