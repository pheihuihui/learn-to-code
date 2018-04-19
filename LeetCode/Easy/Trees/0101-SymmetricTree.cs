public class Solution
{
    public bool IsSymmetric(TreeNode root)
    {
        return IsSameTree(root, Mirror(root));
    }
    private bool IsSameTree(TreeNode root1, TreeNode root2)
    {
        if (root1 == null && root2 == null)
        {
            return true;
        }
        if ((root1 == null && root2 != null) || (root1 != null && root2 == null))
        {
            return false;
        }
        if (root1.val != root2.val)
        {
            return false;
        }
        return IsSameTree(root1.left, root2.left) && IsSameTree(root1.right, root2.right);
    }
    private TreeNode Mirror(TreeNode root)
    {
        TreeNode newtree = null;
        if (root == null)
        {
            return newtree;
        }
        else if((root.left == null) && (root.right == null))
        {
            newtree = new TreeNode(root.val);
            return newtree;
        }
        else if((root.left == null) && (root.right != null))
        {
            newtree = new TreeNode(root.val);
            newtree.left = Mirror(root.right);
            newtree.right = null;
            return newtree;
        }
        else if((root.right == null) && (root.left != null))
        {
            newtree = new TreeNode(root.val);
            newtree.right = Mirror(root.left);
            newtree.left = null;
            return newtree;
        }
        else
        {
            newtree = new TreeNode(root.val);
            newtree.left = Mirror(root.right);
            newtree.right = Mirror(root.left);
            return newtree;
        }
    }
}

//try not to use extra space