public class Solution
{
    public int MissingNumber(int[] nums)
    {
        int len = nums.Length;
        List<int> ls = new List<int>();
        for(int i = 0; i <= len; i++)
        {
            ls.Add(i);
        }
        for(int i = 0; i < len; i++)
        {
            ls.Remove(nums[i]);
        }
        return ls.Last();
    }
}