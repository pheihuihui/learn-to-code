
function sumNumbers(root: TreeNode | null): number {
    let tmp = getPaths(root)
    let res = 0
    for (const u of tmp) {
        res += Number(u)
    }
    return res
};

function getPaths(root: TreeNode | null): string[] {
    if (root == null) {
        return []
    } else if (root.left == null && root.right == null) {
        return [root.val.toString()]
    } else {
        let left = getPaths(root.left)
        let right = getPaths(root.right)
        let res = [] as string[]
        for (const u of left) {
            res.push(root.val.toString() + u)
        }
        for (const u of right) {
            res.push(root.val.toString() + u)
        }
        return res
    }
}