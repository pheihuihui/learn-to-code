class Solution {
    func addToArrayForm(_ A: [Int], _ K: Int) -> [Int] {
        var B = [Int]()
        var kk = K
        while kk != 0 {
            let b = kk % 10
            B.append(b)
            kk /= 10
        }
        let rA = A.reversed() as [Int]
        let lenA = A.count
        let lenB = B.count
        var rAB = lenA > lenB ? rA : B
        if lenA > lenB {
            var index = 0
            for i in B {
                rAB[index] += i
                index += 1
            }
        } else {
            var index = 0
            for i in rA {
                rAB[index] += i
                index += 1
            }
        }
        rAB.append(0)
        let len = rAB.count
        for u in 0...(len - 2) {
            if rAB[u] >= 10 {
                rAB[u] -= 10
                rAB[u + 1] += 1
            }
        }
        var res = rAB.reversed() as [Int]
        if res[0] == 0 && res.count > 1 {
            res.removeFirst()
        }
        return res
    }
}