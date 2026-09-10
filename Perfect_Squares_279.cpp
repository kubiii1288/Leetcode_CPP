//
// Created by Anh Le on 5/7/26.
//
int numSquares(int n) {
    vector<int> nums;
    for (int i = 1; i * i <= n; i++) {
        nums.push_back(i * i);
    }
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int square : nums) {
            if (i - square >= 0 && dp[i - square] != 1e9) {
                dp[i] = min(dp[i], 1 + dp[i - square]);
            }
        }
    }
    return dp[n];
}

int numSquares(int n) {
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j] +1);
        }
    }
    return dp[n];
}