class Solution {
    func increasingTriplet(_ nums: [Int]) -> Bool {
        var pos0 = Int.max
        var pos1 = Int.max
        var pos2 = Int.max
        if nums.count < 3 {
            return false
        } else {
            for u in nums.indices {
                let tmp = nums[u]
                if tmp <= pos0 {
                    pos0 = tmp
                } else if tmp <= pos1 {
                    pos2 = tmp
                    pos1 = pos0
                } else if tmp <= pos2 {
                    pos2 = tmp
                } else if tmp > pos2 {
                    return true
                }
            }
        }
        return false
    }
}