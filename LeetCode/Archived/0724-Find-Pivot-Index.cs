public class Solution
{
    public int PivotIndex(int[] nums)
    {
        int sum = 0;
        for(int i = 0; i < nums.Length; i++)
        {
            sum += nums[i];
        }
        int tmp = 0;
        for(int i = 0; i < nums.Length; i++)
        {
            tmp += nums[i];
            if ((tmp - nums[i]) * 2 == (sum - nums[i]))
                return i;
        }
        return -1;
    }
}