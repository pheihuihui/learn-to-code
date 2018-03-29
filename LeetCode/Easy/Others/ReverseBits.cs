public class Solution
{
    public uint reverseBits(uint n)
    {
        uint res = 0;
        for(int i = 1; i <= 32; i++)
        {
            res *= 2;
            if(n != 0)
            {
                res += (n % 2);
                n /= 2;
            }
            else
            {
                res += 0;
            }
        }
        return res;
    }
}