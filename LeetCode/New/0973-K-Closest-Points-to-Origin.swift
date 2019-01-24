class Solution {
    func kClosest(_ points: [[Int]], _ K: Int) -> [[Int]] {
        var dic: [Int: [Int]] = [Int: [Int]]()
        var index = 0
        for i in points {
            let distant = i[0] * i[0] + i[1] * i[1]
            if dic[distant] != nil {
                dic[distant]?.append(index)
            } else {
                dic[distant] = [index]
            }
            index += 1
        }
        let sdic = dic.sorted {
            (a, b) -> Bool in
            return a.key < b.key
        }
        var inds: [Int] = [Int]()
        for i in sdic {
            if inds.count >= K {
                break
            } else {
                for j in i.value {
                    inds.append(j)
                }
            }
        }
        var res: [[Int]] = [[Int]]()
        for i in inds {
            res.append(points[i])
        }
        return res
    }
}