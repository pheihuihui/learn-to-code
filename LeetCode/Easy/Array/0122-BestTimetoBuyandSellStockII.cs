public class Solution
{
    public int MaxProfit(int[] prices)
    {
        int profit = 0;
        if (prices == null || prices.Length == 0)
            return 0;
        else if (prices.Length == 1)
            return 0;
        else
        {
            for (int i = 1; i < prices.Length; i++)
            {
                if (prices[i] - prices[i - 1] > 0)
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
    }
}

//slow