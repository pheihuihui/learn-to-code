public class Solution
{
    public int RemoveDuplicates(int[] nums)
    {
        int len = 1;
        if (nums.Length == 0 || nums == null)
            return 0;
        else if (nums.Length == 1)
            return 1;
        else
        {
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] != nums[i - 1])
                {
                    nums[len] = nums[i];
                    len += 1;
                }
            }
            return len;
        }
    }
}