using System.Text.RegularExpressions;    
public class Solution
{
    public bool IsPalindrome(string s)
    {
        if(s.Length == 0 || s.Length == 1)
        {
            return true;
        }
        string res = Regex.Replace(s, "[^a-zA-Z0-9]", "").ToLower();
        if(res == "")
        {
            return true;
        }
        int ii = 0;
        int jj = res.Length - 1;
        while(ii < jj)
        {
            if(res[ii] != res[jj])
            {
                return false;
            }
            ii++;
            jj--;
        }
        return true;
    }
}