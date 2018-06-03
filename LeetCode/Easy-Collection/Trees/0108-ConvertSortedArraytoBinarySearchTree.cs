public class Solution
{
    public TreeNode SortedArrayToBST(int[] nums)
    {
        TreeNode res;
        switch (nums.Length)
        {
            case 0:
                return null;
            case 1:
                res = new TreeNode(nums[0]);
                break;
            case 2:
                res = new TreeNode(nums[1]);
                res.left = new TreeNode(nums[0]);
                break;
            case 3:
                res = new TreeNode(nums[1]);
                res.left = new TreeNode(nums[0]);
                res.right = new TreeNode(nums[2]);
                break;
            default:
                {
                    res = new TreeNode(nums[nums.Length / 2]);
                    int[] lnums = new int[nums.Length / 2];
                    int[] rnums = new int[nums.Length - nums.Length / 2 - 1];
                    for(int i = 0; i < nums.Length / 2; i++)
                    {
                        lnums[i] = nums[i];
                    }
                    for(int i = nums.Length / 2 + 1; i < nums.Length; i++)
                    {
                        rnums[i - nums.Length / 2 - 1] = nums[i];
                    }
                    res.left = SortedArrayToBST(lnums);
                    res.right = SortedArrayToBST(rnums);
                    break;
                }
        }
        return res;
    }
}