class Solution {
    func strWithout3a3b(_ A: Int, _ B: Int) -> String {
        var x, y: Int
        var tail = ""
        var big = A >= B ? A : B
        var small = A < B ? A : B
        x = big - small
        y = small * 2 - big
        if y < 0 {
            big -= 2
            x = big - small
            y = small * 2 - big
            if small == A && big + 2 == B{
                tail = "bb"
            } else {
                tail = "aa"
            }
        }
        var res = ""
        if x > 0 {
            if big + tail.count == A {
                for _ in 1...x {
                    res.append("aab")
                }
            } else {
                for _ in 1...x {
                    res.append("bba")
                }
            }
        }
        if y > 0 {
            if big + tail.count == A {
                for _ in 1...y {
                    res.append("ab")
                }
            } else {
                for _ in 1...y {
                    res.append("ba")
                }
            }
        }
        res.append(tail)
        return res
    }
}