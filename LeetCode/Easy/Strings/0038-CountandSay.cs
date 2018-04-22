public class Solution
{
    public string CountAndSay(int n)
    {
        if(n > 1)
        {
            return CountNext(CountAndSay(n - 1));
        }
        else
        {
            return "1";
        }
    }
    public string CountNext(string s)
    {
        string res = "";
        s += "s";
        int ct = 1;
        for(int i = 1; i < s.Length; i++)
        {
            if(s[i] == s[i - 1])
            {
                ct += 1;
            }
            else
            {
                res += ct.ToString() + s[i - 1];
                ct = 1;
            }
        }
        return res;
    }
}