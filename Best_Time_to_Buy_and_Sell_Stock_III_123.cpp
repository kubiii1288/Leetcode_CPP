//
// Created by Anh Le on 2/25/26.
//
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
    for (int i = 1; i <= 2; i++) {
        int best_prev = dp[i - 1][0] - prices[0];
        for (int j = 1; j < prices.size(); j++) {
            dp[i][j] = max(dp[i][j - 1], prices[j] + best_prev);
            best_prev = max(best_prev, dp[i - 1][j] - prices[j]);
        }
    }
    return dp.back().back();
}