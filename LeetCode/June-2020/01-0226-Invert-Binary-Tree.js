var invertTree = function (root) {
    if (root == null) return null
    if (root) {
        [root.left, root.right] = [invertTree(root.right), invertTree(root.left)]
    }
    return root
};