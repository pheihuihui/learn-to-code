public class TreeNode 
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) 
    { 
        val = x; 
    }
}

public class Solution
{
    public int MaxDepth(TreeNode root)
    {
        int res = 1;
        if (root == null)
        {
            return 0;
        }
        int ld, rd;
        if(root.left == null)
        {
            ld = 0;
        }
        else
        {
            ld = MaxDepth(root.left);
        }
        if(root.right == null)
        {
            rd = 0;
        }
        else
        {
            rd = MaxDepth(root.right);
        }
        res += (ld >= rd ? ld : rd);
        return res;
    }
}