//
// Created by kubiii on 10/18/26.
//

int maxA(int n) {
    vector<int> dp(n+1,0);
    iota(dp.begin(), dp.end(),0);
    for (int i = 0; i <= n-1; i++) {
        for (int j = i + 3; j <= min(n,i+6); j++) {
            dp[i] = max(dp[i], (j-i-1) * dp[i]);
        }
    }
    return dp[n];
}