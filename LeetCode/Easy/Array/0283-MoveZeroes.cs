public class Solution
{
    public void MoveZeroes(int[] nums)
    {
        List<int> vs = new List<int>();
        int zeros = 0;
        for(int i = 0; i < nums.Length; i++)
        {
            if(nums[i] == 0)
            {
                zeros += 1;
            }
            else
            {
                vs.Add(nums[i]);
            }
        }
        for(int i = 0; i < zeros; i++)
        {
            vs.Add(0);
        }
        int[] res = vs.ToArray();
        for(int i = 0; i < nums.Length; i++)
        {
            nums[i] = res[i];
        }
    }
}