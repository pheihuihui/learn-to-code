class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var dic: [Int: Int] = [:]
        var tmp: [Int: [Int]] = [:]
        for u in nums {
            if dic[u] != nil {
                dic[u]! += 1
            } else {
                dic[u] = 1
            }
        }
        for u in dic {
            if tmp[u.value] != nil {
                tmp[u.value]!.append(u.key)
            } else {
                tmp[u.value] = [u.key]
            }
        }
        var res: [Int] = []
        for u in tmp.keys.sorted().reversed() {
            for s in tmp[u]! {
                res.append(s)
                if res.count == k {
                    return res
                }
            }
        }
        return res
    }
}