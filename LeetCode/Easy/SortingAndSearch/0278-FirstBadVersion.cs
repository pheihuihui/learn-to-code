public class Solution : VersionControl
{
    public int FirstBadVersion(int n)
    {
        int a = n;
        int b = n - a / 2;
        while( a / 2 >= 3)
        {
            a /= 2;
            if (IsBadVersion(b))
            {
                b -= a / 2;
            }
            else
            {
                b += a / 2;
            }
        }
        if (IsBadVersion(b))
        {
            while (IsBadVersion(b))
            {
                b--;
            }
            b += 1;
        }
        else
        {
            while (!IsBadVersion(b))
            {
                b++;
            }
        }
        return b;
    }
}