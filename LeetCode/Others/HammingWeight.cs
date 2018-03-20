public class Solution 
{
    public int HammingWeight(uint n)
    {
        uint res = 0;
        while(n != 0)
        {
            res += n % 2;
            n /= 2;
        }
        return (int)res;
    }
}