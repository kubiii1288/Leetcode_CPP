//
// Created by Anh Le on 8/15/26.
//

int numTilings(int n) {
    if (n < 3)
        return n;
    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 1);
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3] % MOD) % MOD;
    }
    return dp.back();
}