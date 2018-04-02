public class Solution
{
    public int MaxProfit(int[] prices)
    {
        int res = 0;
        for(int i = 0; i < prices.Length; i++)
        {
            if(i < prices.Length - 1)
            {
                if(prices[i] > prices[i + 1])
                {
                    continue;
                }
            }
            for(int j = i; j < prices.Length; j++)
            {
                if (prices[j] - prices[i] > res)
                {
                    res = prices[j] - prices[i];
                }
            }
        }
        return res;
    }
}

//slow