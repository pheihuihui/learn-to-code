class Solution {
    func subsets(_ nums: [Int]) -> [[Int]] {
        if nums.count == 0 {
            return []
        } else if nums.count == 1 {
            return [nums, []]
        } else {
            let head = nums[0]
            var tail = nums
            tail.remove(at: 0)
            var res: [[Int]] = []
            for i in subsets(tail) {
                res.insert(i, at: 0)
                var u = i
                u.insert(head, at: 0)
                res.insert(u, at: 0)
            }
            return res
        }
    }
}