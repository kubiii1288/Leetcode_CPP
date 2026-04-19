//
// Created by Anh Le on 1/21/26.
//
bool solve(string &s, int from, int to, vector<vector<int>> &dp, unordered_set<string> &dict)
{
    if (dp[from][to] != -1) return dp[from][to];
    if (dict.find(s.substr(from,to-from)) != dict.end())
    {
        dp[from][to] = 1;
    } else
    {
        bool valid = false;
        for (int i = from + 1; !valid && i < to; i++)
        {
            valid = (solve(s,from, i, dp,dict) && solve(s,i,to,dp,dict));
        }
        dp[from][to] = valid;
    }
    return dp[from][to];
}

bool wordBreak(string &s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for (string &s : wordDict)
        dict.insert(s);
    vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));

    return solve(s,0,s.size(),dp,dict);
}