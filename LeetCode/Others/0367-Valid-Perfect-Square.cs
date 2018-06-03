public class Solution
{
    public bool IsPerfectSquare(int num)
    {
        int tmp = 46340;
        int tt = tmp;
        while (true)
        {
            if (num > 46340 * 46340)
                return false;
            if (tmp * tmp == num)
                return true;
            else if(tmp * tmp > num)
            {
                if (tt > 2)
                {
                    tt /= 2;
                    tmp -= tt;
                }
                else
                    tmp -= 1;
                if (tmp * tmp < num && (tmp + 1) * (tmp + 1) > num)
                    return false;
            }
            else if(tmp * tmp < num)
            {
                if (tt > 2)
                {
                    tt /= 2;
                    tmp += tt;
                }
                else
                    tmp += 1;
                if (tmp * tmp > num && (tmp - 1) * (tmp - 1) < num)
                    return false;
            }
        }
    }
}