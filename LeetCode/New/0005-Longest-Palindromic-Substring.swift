class Solution {
    func longestPalindrome(_ s: String) -> String {
        var res: String = ""
        var curlenth = 0
        for u in s.indices {
            var tmp: Substring = ""
            var index_begin = u
            var index_end = u
            while index_begin > s.startIndex && index_end < s.index(s.endIndex, offsetBy: -1) {
                let bfr = s.index(before: index_begin)
                let aft = s.index(after: index_end)
                if s[bfr] == s[aft] {
                    index_begin = bfr
                    index_end = aft
                } else {
                    break
                }
            }
            tmp = s[index_begin ... index_end]
            index_begin = u
            if index_begin < s.index(s.endIndex, offsetBy: -1) {
                index_end = s.index(after: index_begin)
                while index_begin > s.startIndex && index_end < s.index(s.endIndex, offsetBy: -1) {
                    if s[index_begin] != s[index_end] {
                        break
                    }
                    let bfr = s.index(before: index_begin)
                    let aft = s.index(after: index_end)
                    if s[bfr] == s[aft] {
                        index_begin = bfr
                        index_end = aft
                    } else {
                        break
                    }
                }
                if s[index_begin] == s[index_end] {
                    let tmpp = s[index_begin ... index_end]
                    if tmpp.count > tmp.count {
                        tmp = tmpp
                    }
                }
            }
            if tmp.count > curlenth {
                curlenth = tmp.count
                res = String(tmp)
            }
        }
        return res
    }
}