class Solution {
    func flipMatchVoyage(_ root: TreeNode?, _ voyage: [Int]) -> [Int] {
        var res = [Int]()
        if root == nil && voyage.count == 0 {
            return []
        } else if root == nil && voyage.count != 0 {
            return [-1]
        } else if root != nil && voyage.count == 0 {
            return [-1]
        } else if root?.val != voyage[0] {
            return [-1]
        } else {
            if root?.left == nil && root?.right == nil {
                return []
            } else if root?.left == nil {
                let rvalue = root!.right!.val
                let rvoy = cutArray(voyage, rvalue, -1)
                let rres = flipMatchVoyage(root!.right, rvoy)
                if rres == [-1] {
                    res = [-1]
                } else {
                    res.append(contentsOf: rres)
                }
            } else if root?.right == nil {
                let lvalue = root!.left!.val
                let lvoy = cutArray(voyage, lvalue, -1)
                let lres = flipMatchVoyage(root!.left, lvoy)
                if lres == [-1] {
                    res = [-1]
                } else {
                    res.append(contentsOf: lres)
                }
            } else {
                var ll = root!.left!.val
                var rr = root!.right!.val
                if ll != voyage[1] {
                    if rr == voyage[1] {
                        let node = root?.left
                        root?.left = root?.right
                        root?.right = node
                        res.append(root!.val)
                    } else {
                        res = [-1]
                        return res
                    }
                }
                ll = root!.left!.val
                rr = root!.right!.val
                let lvoy = cutArray(voyage, ll, rr)
                let rvoy = cutArray(voyage, rr, -1)
                let lres = flipMatchVoyage(root!.left!, lvoy)
                let rres = flipMatchVoyage(root!.right!, rvoy)
                if lres == [-1] || rres == [-1] {
                    res = [-1]
                } else {
                    res.append(contentsOf: lres)
                    res.append(contentsOf: rres)
                }
            }
        }
        return res
    }
    
    func cutArray(_ arr: [Int], _ start: Int, _ end: Int) -> [Int] {
        var res = [Int]()
        var bb = false
        for i in arr {
            if i == start {
                bb = true
            }
            if i == end {
                bb = false
                break
            }
            if bb {
                res.append(i)
            }
        }
        return res
    }
}