public class Solution
{
    public void Rotate(int[] nums, int k)
    {
        int extra;
        for (int i = 1; i <= k % nums.Length; i++)
        {
            extra = nums[nums.Length - 1];
            for (int j = nums.Length - 1; j >= 1; j--)
            {
                nums[j] = nums[j - 1];
            }
            nums[0] = extra;
        }
    }
}