//
// Created by Anh Le on 8/15/26.
//

int maxProfit(vector<int>& prices, int fee) {
    vector<int> cash(prices.size(),0);
    vector<int> hold(prices.size(),0);
    hold[0] = -prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        cash[i] = max(cash[i-1], hold[i-1] + prices[i] - fee);
        hold[i] = max(hold[i-1], cash[i-1] - prices[i]);
    }
    return cash.back();
}