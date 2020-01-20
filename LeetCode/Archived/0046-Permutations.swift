class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        if nums.count == 0 {
            return []
        } else if nums.count == 1 {
            return [nums]
        } else {
            var res: [[Int]] = []
            for u in nums.indices {
                var rest = nums
                rest.remove(at: u)
                let tmp = permute(rest)
                for i in tmp {
                    var k = i
                    k.append(nums[u])
                    res.insert(k, at: 0)
                }
            }
            return res
        }
    }
}
