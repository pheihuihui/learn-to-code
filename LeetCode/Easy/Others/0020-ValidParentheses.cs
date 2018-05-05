public class Solution
{
    public bool IsValid(string s)
    {
        if (s.Length == 0)
            return true;
        if (s[0] == ')' || s[0] == ']' || s[0] == '}' || s.Length % 2 == 1)
            return false;
        Stack<char> st = new Stack<char>();
        for(int i = 0; i < s.Length; i++)
        {
            if (s[i] == '(')
                st.Push(')');
            else if (s[i] == '[')
                st.Push(']');
            else if (s[i] == '{')
                st.Push('}');
            else
            {
                if(st.Count > 0)
                {
                    if(st.Peek() == s[i])
                    {
                        st.Pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if(st.Count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}