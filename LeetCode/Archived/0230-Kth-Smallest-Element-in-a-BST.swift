class Solution {
    func kthSmallest(_ root: TreeNode?, _ k: Int) -> Int {
        if let node = root {
            let ll = countTree(node.left)
            if k <= ll {
                return kthSmallest(node.left, k)
            } else if k == ll + 1 {
                return node.val
            } else {
                return kthSmallest(node.right, k - ll - 1)
            }
        } else {
            return 0
        }
    }

    func countTree(_ root: TreeNode?) -> Int {
        if let node = root {
            return countTree(node.left) + countTree(node.right) + 1
        } else {
            return 0
        }
    }
}

// too slow