public class Solution
{
    public int SingleNumber(int[] nums)
    {
        int len = nums.Length;
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < len; j++)
            {
                if(nums[i] == nums[j])
                {
                    int tmp1 = nums[len - 1];
                    nums[len - 1] = nums[i];
                    nums[i] = tmp1;
                    int tmp2 = nums[len - 2];
                    nums[len - 2] = nums[j];
                    nums[j] = tmp2;
                    len -= 2;
                    SingleNumber(nums);
                }
            }
        }
        return nums[0];
    }
}