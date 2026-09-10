//
// Created by Anh Le on 1/21/26.
//
int maxLen = -1;
bool solve(int index, int N, string& s, unordered_set<string>& dict,
           vector<int>& dp) {
    if (dp[index] != -1)
        return dp[index];
    bool valid = false;
    for (int len = 1; len <= maxLen && index + len <= N && !valid; len++) {
        if (dict.find(s.substr(index, len)) != dict.end()) {
            valid = solve(index + len, N, s, dict, dp);
        }
    }
    return dp[index] = valid;
}
bool wordBreak(string s, vector<string>& wordDict) {
    const unsigned int N = s.size();
    unordered_set<string> dict;
    for (string& s : wordDict) {
        dict.insert(s);
        maxLen = max(maxLen, (int)s.size());
    }
    vector<int> dp(N + 1, -1);
    dp.back() = true;
    return solve(0, N, s, dict, dp);
}