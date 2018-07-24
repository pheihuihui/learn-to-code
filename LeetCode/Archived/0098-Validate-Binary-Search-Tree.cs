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
    public List<int> ll = new List<int>();
    public bool IsValidBST(TreeNode root)
    {
        Traverse(root);
        int[] nums = ll.ToArray();
        if (nums.Length == 1)
        {
            return true;
        }
        else
        {
            for(int i = 1; i < nums.Length; i++)
            {
                if(nums[i] <= nums[i - 1])
                {
                    return false;
                }
            }
            return true;
        }
    }
    public void Traverse(TreeNode root)
    {
        if(root != null)
        {
            if(root.left != null)
            {
                Traverse(root.left);
            }
            ll.Add(root.val);
            if(root.right != null)
            {
                Traverse(root.right);
            }
        }
    }
}