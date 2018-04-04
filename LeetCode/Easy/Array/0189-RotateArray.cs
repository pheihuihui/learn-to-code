public class Solution
{
    public void Rotate(int[] nums, int k)
    {
        int kk = k % nums.Length;
        int[] tmp = new int[kk];
        for(int i = nums.Length - kk; i < nums.Length; i++)
        {
            tmp[i - nums.Length + kk] = nums[i];
        }
        for(int i = nums.Length - 1; i >= kk; i--)
        {
            nums[i] = nums[i - kk];
        }
        for(int i = 0; i < kk; i++)
        {
            nums[i] = tmp[i];
        }
    }
}

//todo: find O(1) space solution