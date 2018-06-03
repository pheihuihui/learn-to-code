public class Solution
{
    public int StrStr(string haystack, string needle)
    {
        if(needle.Length == 0)
        {
            return 0;
        }
        else if(needle.Length > haystack.Length)
        {
            return -1;
        }
        else
        {
            for(int i = 0; i <= haystack.Length - needle.Length; i++)
            {
                bool res = true;
                for(int j = 0; j < needle.Length; j++)
                {
                    if(haystack[j + i] != needle[j])
                    {
                        res = false;
                        break;
                    }
                }
                if(res == true)
                {
                    return i;
                }
            }
        }
        return -1;
    }
}