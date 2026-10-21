//
// Created by kubiii on 10/19/26.
//
const int MOD = 1e9+7;
inline int mul(int a, int b) {
    return ((long long) (a) * b) % MOD;
}
int numberOfWays(int numPeople) {
    vector<int>dp(numPeople+1,0);
    dp[0] =1;
    for (int i = 2; i <= numPeople; i+=2) {
        for (int j = 1; j < i; j+=2) {
            dp[i] = (dp[i] + mul(dp[j-1], dp[i-j-1])) % MOD;
        }
    }
    return dp[numPeople];
}