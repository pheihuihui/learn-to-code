public class Solution 
{
    public int HammingDistance(int x, int y) 
    {
        int res = 0;
        while(y != 0 || x != 0)
        {
            res += (( y % 2 ) == ( x % 2 )? 0 : 1);
            y /= 2;
            x /= 2;
        }
        return res;
    }
}