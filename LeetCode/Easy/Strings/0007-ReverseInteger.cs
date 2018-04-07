public class Solution
{
    public int Reverse(int x)
    {
        Int64 i = 0;
        while(x != 0)
        {
            i *= 10;
            i += x % 10;
            x /= 10;
        }
        if(i > Int32.MaxValue || i < Int32.MinValue)
        {
            return 0;
        }
        else
        {
            return (Int32)i;
        }
    }
}