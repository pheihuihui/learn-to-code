public class Solution
{
    public List<List<int>> Generate(int numRows)
    {
        List<List<int>> ls = new List<List<int>>();
        List<int> head = new List<int>() { 1 };
        if(numRows == 0)
        {
            return ls;
        }
        else
        {
            for(int i = 1; i <= numRows; i++)
            {
                ls.Add(head);
                head = GetNextRow(head);
            }
        }
        return ls;
    }
    
    public List<int> GetNextRow(List<int> ls)
    {
        int[] nums = ls.ToArray();
        int len = ls.Count;
        List<int> res = new List<int>();
        for(int i = 0; i <= len; i++)
        {
            if(i == 0 || i == len)
            {
                res.Add(1);
            }
            else
            {
                res.Add(nums[i] + nums[i - 1]);
            }
        }
        return res;
    }
}