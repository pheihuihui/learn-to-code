class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var res = 0
        var len = 0
        var chs = ""
        if s.count == 0 {
            return 0
        } else {
            for index in s.indices {
                let tmp = s[index]
                if chs.contains(tmp) {
                    let chsc = chs
                    for u in chsc.indices {
                        if chsc[u] == tmp {
                            chs = String(chsc.suffix(from: u))
                            chs.removeFirst()
                            len = chs.count
                            break
                        }
                    }
                }
                chs.append(tmp)
                len += 1
                if len > res {
                    res = len
                }
            }
        }
        return res
    }
}

// too slow