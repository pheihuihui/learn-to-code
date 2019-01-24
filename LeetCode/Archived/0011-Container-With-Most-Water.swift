class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var xmap = [Int:[Int]]()
        var res: Int = 0
        var left: Int = 0
        var right: Int = 0
        var index: Int = 1
        for i in height {
            if xmap[i] != nil {
                xmap[i]?.append(index)
            } else {
                xmap[i] = [Int]()
                xmap[i]?.append(index)
            }
            index += 1
        }
        var keys = [Int]()
        for x in xmap {
            keys.append(x.key)
        }
        let tmp = findMax(keys)
        left = findMin(xmap[tmp]!)
        right = findMax(xmap[tmp]!)
        res = tmp * (right - left)
        for i in (1...tmp).reversed() {
            let arr = xmap[i]
            if xmap[i] != nil {
                let ll = findMin(arr!)
                let rr = findMax(arr!)
                if ll < left {
                    left = ll
                }
                if rr > right {
                    right = rr
                }
                let ret = i * (right - left)
                if ret > res {
                    res = ret
                }
            }
        }
        return res
    }
    
    func findMax(_ nums: [Int]) -> Int {
        var res: Int = 0
        for i in nums {
            if i > res {
                res = i
            }
        }
        return res
    }
    
    func findMin(_ nums: [Int]) -> Int {
        var res: Int = Int.max
        for i in nums {
            if i < res {
                res = i
            }
        }
        return res
    }
}

//tooooo slow