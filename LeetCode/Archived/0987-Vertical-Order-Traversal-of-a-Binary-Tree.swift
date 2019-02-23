class Solution {
    var tmp = [Int : [Int : [Int]]]()
    
    func verticalTraversal(_ root: TreeNode?) -> [[Int]] {
        recordNode(root, Coordinate(0, 0))
        var res = [[Int]]()
        let outks = Array(tmp.keys).sorted(by: <)
        for i in outks {
            var tmq = [Int]()
            let inks = Array(tmp[i]!.keys).sorted(by: >)
            for u in inks {
                let vals = Array(tmp[i]![u]!).sorted(by: <)
                for x in vals {
                    tmq.append(x)
                }
            }
            res.append(tmq)
        }
        return res
    }
    
    func recordNode(_ root: TreeNode?, _ coord: Coordinate) {
        if root == nil {
            return
        } else {
            let a = coord.x
            let b = coord.y
            if tmp[a] != nil {
                if tmp[a]![b] != nil {
                    tmp[a]![b]!.append(root!.val)
                } else {
                    tmp[a]![b] = [root!.val]
                }
            } else {
                tmp[a] = [b : [root!.val]]
            }
            recordNode(root!.left, Coordinate(coord.x - 1, coord.y - 1))
            recordNode(root!.right, Coordinate(coord.x + 1, coord.y - 1))
        }
    }
}

class Coordinate {
    var x: Int
    var y: Int
    init(_ a: Int, _ b: Int) {
        x = a
        y = b
    }
}