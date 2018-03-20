public class Solution
{
    public string ReverseString(string s)
    {
        char[] ch = s.ToCharArray();
        int left = 0;
        int right = s.Length - 1;
        while(left < right)
        {
            char m = ch[left];
            ch[left] = ch[right];
            ch[right] = m;
            left++;
            right--;
        }
        return new string(ch);
    }
}