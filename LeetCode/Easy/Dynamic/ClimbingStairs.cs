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
        else
        {
            int a = down;
            int b = up;
            int c = up;
            for (int i = 0; i < up - 1; i++)
            {
                a *= down - 1;
                down -= 1;
                b *= c - 1;
                c -= 1;
            }
            return a / b;
        }
    }
}