//
//  CircleImage.swift
//  swiftui01
//
//  Created by feihuihui on 2019/6/16.
//  Copyright © 2019 feihuihui. All rights reserved.
//

import SwiftUI

struct CircleImage : View {
    var body: some View {
        Image("turtlerock")
        .clipShape(Circle())
        .overlay(Circle().stroke(Color.white, lineWidth: 5))
        .shadow(radius: 4)
    }
}

#if DEBUG
struct CircleImage_Previews : PreviewProvider {
    static var previews: some View {
        CircleImage()
    }
}
#endif
