using System.Text.RegularExpressions;
public class Solution
{
    public int MyAtoi(string str)
    {
        string res = "";
        str = str.Trim();
        if (!Regex.IsMatch(str, "^[+-]?[0-9]+[^0-9]*"))
        {
            return 0;
        }
        else
        {
            if(str[0] == '-' || str[0] == '+')
            {
                res += str[0];
                for (int i = 1; i < str.Length; i++)
                {
                    if ("0123456789".Contains(str[i]))
                    {
                        res += str[i];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                for (int i = 0; i < str.Length; i++)
                {
                    if ("0123456789".Contains(str[i]))
                    {
                        res += str[i];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if(res.TrimStart('-', '+', '0').Length >= 12 && res[0] == '-')
        {
            return Int32.MinValue;
        }
        else if(res.TrimStart('-', '+', '0').Length >= 11 && res[0] != '-')
        {
            return Int32.MaxValue;
        }
        else
        {
            Int64 aa = Convert.ToInt64(res);
            if (aa <= Int32.MinValue)
            {
                return Int32.MinValue;
            }
            else if (aa >= Int32.MaxValue)
            {
                return Int32.MaxValue;
            }
            else
            {
                return (int)aa;
            }
        }
    }
}

//fu......