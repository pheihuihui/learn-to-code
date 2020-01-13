class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        var dic: [Int: Int] = [:]
        for u in nums {
            if dic[u] != nil {
                dic[u]! += 1
            } else {
                dic[u] = 1
            }
        }
        var count = 1
        for u in dic.keys.sorted().reversed() {
            let n = dic[u]!
            if count <= k && k < count + n {
                return u
            } else {
                count += n
            }
        }
        return 0
    }
}