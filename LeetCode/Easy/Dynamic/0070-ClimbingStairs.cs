public class Solution
{
    public int ClimbStairs(int n)
    {
        int res = 0;
        int maxtwos = n / 2;
        for (int i = 0; i <= maxtwos; i++)
        {
            int ones = n - i * 2;
            res += CountCombinations(ones + i, i);
        }
        return res;
    }
    public int CountCombinations(int down, int up)
    {
        if(up == 0)
        {
            return 1;
        }
        else if(up == 1)
        {
            return down;
        }
        else
        {
            double res = 1;
            for(int i = up; i >= 1; i--)
            {
                res *= ((double)down / (double)up);
                up--;
                down--;
            }
            return (int)(res + 0.01f);
        }
    }
}