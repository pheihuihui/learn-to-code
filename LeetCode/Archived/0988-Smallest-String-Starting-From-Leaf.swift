class Solution {
    func smallestFromLeaf(_ root: TreeNode?) -> String {
        if root == nil {
            return ""
        } else if root!.left == nil && root!.right == nil {
            var res = ""
            let u = UnicodeScalar(root!.val + 97)
            let ch = Character(u!)
            res.append(ch)
            return res
        } else {
            let lef = smallestFromLeaf(root!.left)
            let rig = smallestFromLeaf(root!.right)
            var smaller = getSmaller(lef, rig)
            let u = UnicodeScalar(root!.val + 97)
            let ch = Character(u!)
            smaller.append(ch)
            return smaller
        }
    }
    func getSmaller(_ left: String, _ right: String) -> String {
        if left == "" && right == "" {
            return ""
        } else if left == "" {
            return right
        } else if right == "" {
            return left
        } else {
            var ll = left
            var rr = right
            while (ll != "") && (rr != "") && (ll.first == rr.first) {
                ll.removeFirst()
                rr.removeFirst()
            }
            if (ll == "") && (rr == "") {
                return left
            } else if (ll == "") {
                return left
            } else if (rr == "") {
                return right
            } else {
                if ll.first!.unicodeScalars.first!.value < rr.first!.unicodeScalars.first!.value {   //wtf??
                    return left
                } else {
                    return right
                }
            }
        }
    }
}