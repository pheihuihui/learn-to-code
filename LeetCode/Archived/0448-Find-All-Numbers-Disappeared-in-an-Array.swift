class Solution {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        if nums.count == 0 {
            return [Int]()
        }
        var res = [Int]()
        for _ in 1 ... nums.count {
            res.append(0)
        }
        for i in nums {
            res[i - 1] = i
        }
        var index = 0
        for i in 1 ... nums.count {
            if res[i - 1] == 0 {
                res[index] = i
                index += 1
            }
        }
        var ret = [Int]()
        for i in 0 ..< index {
            ret.append(res[i])
        }
        return ret
    }
}