//
// Created by Anh Le on 2/25/26.
//
int maxProfit(int k, vector<int>& prices) {
    vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < prices.size(); j++) {
            int trade_profit = INT_MIN;
            for (int t = 0; t < j; t++)
                trade_profit =
                    max(trade_profit, prices[j] - prices[t] + dp[i - 1][t]);
            dp[i][j] = max(dp[i][j - 1], trade_profit);
        }
    }
    return dp.back().back();
}