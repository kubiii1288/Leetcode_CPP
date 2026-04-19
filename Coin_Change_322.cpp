//
// Created by Anh Le on 1/18/26.
//
int solve(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount < 0)
        return 1e9;
    if (dp[amount] == -1) {
        int best = 1e9;
        for (int &c : coins)
            best = min(best, solve(coins, amount - c, dp) + 1);
        dp[amount] = best;
    }
    return dp[amount];
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    int ans = solve(coins, amount, dp);
    if(ans == 1e9) return -1;
    return ans;
}