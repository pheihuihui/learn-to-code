public class Solution
{
    public string LongestCommonPrefix(string[] strs)
    {
        if(strs.Length == 0)
        {
            return "";
        }
        string res = strs[0];
        for(int i = 0; i < strs.Length; i++)
        {
            res = LongestCommonPrefix(res, strs[i]);
        }
        return res;
    }
    public string LongestCommonPrefix(string str1, string str2)
    {
        if(str1 == "" || str2 == "")
        {
            return "";
        }
        string res = "";
        int i = 0;
        while (i < (str1.Length <= str2.Length ? str1.Length : str2.Length))
        {
            if(str1[i] == str2[i])
            {
                res += str1[i];
                i++;
            }
            else
            {
                break;
            }
        }
        return res;
    }
}