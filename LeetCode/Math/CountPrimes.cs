public class Solution
{
    public int CountPrimes(int n)
    {
        List<int> primelist = new List<int>();
        primelist.Add(2);
        primelist.Add(3);
        if (n >= 4)
        {
            for (int i = 4; i <= n; i++)
            {
                bool jump = false;
                foreach (int s in primelist)
                {
                    if (i % s == 0)
                    {
                        jump = true;
                        break;
                    }
                    if (s > System.Math.Sqrt(n) + 5)
                    {
                        jump = true;
                        primelist.Add(i);
                        break;
                    }
                }
                if (jump)
                    continue;
                primelist.Add(i);
            }
            if (primelist.Contains(n))
                return primelist.Count - 1;
            else
                return primelist.Count;
        }
        else if (n == 3)
            return 1;
        else
            return 0;
    }
}