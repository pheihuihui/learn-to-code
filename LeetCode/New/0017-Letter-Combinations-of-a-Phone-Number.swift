class Solution {
    func letterCombinations(_ digits: String) -> [String] {
        let maps: [Character: [Character]] = [
            "2": Array("abc"),
            "3": Array("def"),
            "4": Array("ghi"),
            "5": Array("jkl"),
            "6": Array("mno"),
            "7": Array("pqrs"),
            "8": Array("tuv"),
            "9": Array("wxyz"),
        ]
        let arr = Array(digits) as Array<Character>
        var res: [String] = []
        for d in arr {
            res = combine(origin: res, appended: maps[d]!)
        }
        return res
    }

    private func combine(origin: [String], appended: [Character]) -> [String] {
        var res: [String] = []
        if origin.count == 0 {
            for i in appended {
                res.append(String(i))
            }
            return res
        } else {
            for i in origin {
                for u in appended {
                    let nw = i + String(u)
                    res.append(nw)
                }
            }
            return res
        }
    }
}