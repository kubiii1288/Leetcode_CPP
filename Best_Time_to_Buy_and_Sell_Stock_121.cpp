//
// Created by Anh Le on 9/13/25.
//


int maxProfit(vector<int>& prices)
{
    int lowest = prices[0];
    int max_profit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < lowest)
        {
            lowest = prices[i];
        }
        else
        {
            max_profit = std::max(max_profit, prices[i] - lowest);
        }
    }
    return max_profit;
}
