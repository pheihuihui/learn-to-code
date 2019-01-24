class Solution {
    func powerfulIntegers(_ x: Int, _ y: Int, _ bound: Int) -> [Int] {
        var res = [Int]()
        var xx = [Int]()
        var yy = [Int]()
        if x == 0 {
            xx = [0]
        } else if x == 1 {
            xx = [1]
        } else {
            xx.append(1)
            var tmp = x
            while tmp <= bound {
                xx.append(tmp)
                tmp *= x
            }
        }
        
        if y == 0 {
            yy = [0]
        } else if y == 1 {
            yy = [1]
        } else {
            yy.append(1)
            var tmp = y
            while tmp <= bound {
                yy.append(tmp)
                tmp *= y
            }
        }
        
        var tmp = 0
        
        for i in xx {
            for u in yy {
                tmp = i + u
                if !res.contains(tmp) && tmp <= bound {
                    res.append(tmp)
                }
                if tmp > bound {
                    break
                }
            }
        }
        
        return res
    }
}