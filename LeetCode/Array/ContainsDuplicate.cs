public class Solution
{
    public bool ContainsDuplicate(int[] nums)
    {
        if (nums.Length >= 2)
        {
            for (int i = 0; i < nums.Length; i++)
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[j] == nums[i])
                        return true;
                }
            return false;
        }
        else
            return false;
    }
}