class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {
        if numRows == 0 {
            return ""
        } else if numRows == 1 {
            return s
        } else {
            var dic: [Int: [Character]] = [:]
            for u in 1 ... numRows {
                dic[u] = []
            }
            var index = 1
            let unit = numRows * 2 - 2
            for i in s.indices {
                let c = s[i]
                let rest = index % unit == 0 ? unit : index % unit
                let flr = rest <= numRows ? rest : (numRows * 2 - rest)
                print(flr)
                dic[flr]?.append(c)
                index += 1
            }
            var res = ""
            for u in 1 ... numRows {
                res.append(contentsOf: String(dic[u]!))
            }
            return res
        }
    }
}

//slow