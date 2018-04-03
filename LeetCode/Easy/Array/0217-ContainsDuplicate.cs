public class Solution
{
    public bool ContainsDuplicate(int[] nums)
    {
        Dictionary<int, int?> ss = new Dictionary<int, int?>();
        for(int i = 0; i < nums.Length; i++)
        {
            if (ss.GetValueOrDefault(nums[i]) != null)
            {
                return true;
            }
            else
            {
                ss.Add(nums[i], 1);
            }
        }
        return false;
    }
}