//
// Created by Anh Le on 8/15/26.
//

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(cost.size(),0);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < cost.size(); i++)
        dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
    return min(dp[n-2], dp[n-1]);
}

