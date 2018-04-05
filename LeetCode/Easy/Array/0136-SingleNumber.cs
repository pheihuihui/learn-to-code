public class Solution
{
    public int SingleNumber(int[] nums)
    {
        int res = 0;
        Dictionary<int, int?> dc = new Dictionary<int, int?>();
        for(int i = 0; i < nums.Length; i++)
        {
            if(dc.GetValueOrDefault(nums[i]) == null)
            {
                dc.Add(nums[i], 1);
            }
            else
            {
                dc[nums[i]] += 1;
            }
        }
        foreach(int s in dc.Keys)
        {
            if(dc[s].Value == 1)
            {
                res = s;
            }
        }
        return res;
    }
}