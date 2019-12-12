class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var res: [[String]] = []
        var tmp: [String: [String]] = [:]
        for i in strs {
            let hash = simpleHash(i)
            if let st = tmp[hash] {
                tmp[hash]!.append(i)
            } else {
                tmp[hash] = []
                tmp[hash]!.append(i)
            }
        }
        return Array(tmp.values)
    }

    func simpleHash(_ str: String) -> String {
        var letters: [Character: Int] = [:]
        for i in str.indices {
            let ch = str[i]
            if letters.keys.contains(ch) {
                letters[ch]! += 1
            } else {
                letters[ch] = 1
            }
        }
        let aScalars = "a".unicodeScalars
        let aCode = aScalars[aScalars.startIndex].value
        let alphs: [Character] = (0 ..< 26).map {
            i in Character(UnicodeScalar(aCode + i)!)
        }
        var res: String = ""
        for u in alphs {
            if let x = letters[u] {
                res.append(u)
                res.append(String(x))
            }
        }
        return res
    }
}

// too too slow