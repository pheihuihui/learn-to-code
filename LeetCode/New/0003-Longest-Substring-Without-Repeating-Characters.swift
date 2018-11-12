extension String {
    
    var length: Int {
        return count
    }
    
    subscript (i: Int) -> String {
        return self[i ..< i + 1]
    }
    
    func substring(fromIndex: Int) -> String {
        return self[min(fromIndex, length) ..< length]
    }
    
    func substring(toIndex: Int) -> String {
        return self[0 ..< max(0, toIndex)]
    }
    
    subscript (r: Range<Int>) -> String {
        let range = Range(uncheckedBounds: (lower: max(0, min(length, r.lowerBound)),
                                            upper: min(length, max(0, r.upperBound))))
        let start = index(startIndex, offsetBy: range.lowerBound)
        let end = index(start, offsetBy: range.upperBound - range.lowerBound)
        return String(self[start ..< end])
    }
}

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if s.count == 0 || s.count == 1{
            return s.count
        }
        var begin = 0
        var end = 0
        var lastBegin = 0
        var res = 1
        let len = s.count
        while begin <= end {
            let newbegin = varifySubString(begin, end, lastBegin, s)
            if newbegin == -1 {
                if end == len - 1 {
                    let tmp = end - begin + 1
                    if tmp > res {
                        res = tmp
                    }
                    break
                } else {
                    lastBegin = end
                    let tmp = end - begin + 1
                    if tmp > res {
                        res = tmp
                    }
                    end += 1
                }
            } else {
                lastBegin = getLastBegin(newbegin, end, s)
                begin = newbegin + 1
                end = begin + res - 1
                if end > len - 1 {
                    break
                }
            }
        }
        print(begin)
        print(end)
        return res
    }
    
    func varifySubString(_ begin: Int, _ end: Int, _ lastBegin: Int, _ s: String) -> Int {
        if begin == end {
            return -1
        } else {
            for i in lastBegin...end {
                for j in begin..<i {
                    if s[i] == s[j] {
                        return j
                    }
                }
            }
            return -1
        }
    }
    func getLastBegin(_ begin: Int, _ end: Int, _ s: String) -> Int {
        let c = s[begin]
        for i in begin + 1...end {
            if s[i] == c {
                return i
            }
        }
        return -1
    }
    
}


//time limit exceeded, fix it later