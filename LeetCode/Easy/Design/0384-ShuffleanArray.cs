public class Solution
{
    int[] x, s;
    Random rd = new Random();
    public Solution(int[] nums)
    {
        x = new int[nums.Length];
        s = new int[nums.Length];
        Array.Copy(nums, x, nums.Length);
        Array.Copy(nums, s, nums.Length);
    }
    public int[] Reset()
    {
        return x;
    }
    public int[] Shuffle()
    {
        int len = s.Length;
        for (int i = 0; i < len; i++)
        {
            int xx = rd.Next(len);
            int tmp = s[i];
            s[i] = s[xx];
            s[xx] = tmp;
        }
        return s;
    }
}