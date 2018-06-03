public class Solution
{
    public int DominantIndex(int[] nums)
    {
        if (nums.Length == 0)
            return -1;
        if (nums.Length == 1)
            return 0;
        int max = nums[0];
        int index = 0;
        for(int i = 1; i < nums.Length; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
        }
        int[] snums = new int[nums.Length - 1];
        for (int i = 0; i < index; i++)
            snums[i] = nums[i];
        for (int i = index; i < nums.Length - 1; i++)
            snums[i] = nums[i + 1];
        int secmax = snums[0];
        for(int i = 0; i < snums.Length; i++)
        {
            if (snums[i] > secmax)
                secmax = snums[i];
        }
        if (max >= secmax * 2)
            return index;
        else
            return -1;
    }
}