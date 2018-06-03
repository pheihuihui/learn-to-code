public class Solution
{
    public int[] PlusOne(int[] digits)
    {
        if (IsAllNine(digits))
        {
            int[] res = new int[digits.Length + 1];
            res[0] = 1;
            for(int i = 1; i < res.Length; i++)
            {
                res[i] = 0;
            }
            return res;
        }
        digits[digits.Length - 1] += 1;
        for(int i = digits.Length - 1; i > 0; i--)
        {
            if(digits[i] < 10)
            {
                return digits;
            }
            else
            {
                digits[i] = 0;
                digits[i - 1] += 1;
            }
        }
        return digits;
    }
    
    public bool IsAllNine(int[] d)
    {
        for(int i = 0; i < d.Length; i++)
        {
            if(d[i] != 9)
            {
                return false;
            }
        }
        return true;
    }
}