public class Solution
{
    int[] x;
    int[] s;
    public Solution(int[] nums)
    {
        x = nums.ToList().ToArray();
        s = nums.ToList().ToArray();
    }
    
    public int[] Reset()
    {
        return x;
    }
    
    public int[] Shuffle()
    {
        int len = s.Length;
        Random rd = new Random();
        for(int i = 0; i < len; i++)
        {
            int xx = rd.Next(len);
            int tmp = s[i];
            s[i] = s[xx];
            s[xx] = tmp;
        }
        return s;
    }
}