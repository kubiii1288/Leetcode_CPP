//
// Created by Anh Le on 9/24/26.
//
const int MOD = 1e9+7;
int countHomogenous(string s) {
    long long ans = 1;
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        cnt = (s[i] == s[i-1]) ? (cnt +1) : 1;
        ans = (ans + cnt) % MOD;
    }
    return ans;
}