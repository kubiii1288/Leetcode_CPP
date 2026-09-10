//
// Created by Anh Le on 5/1/26.
//
bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    const int M = s1.size();
    const int N = s2.size();
    vector<vector<bool>> dp(M+1, vector<bool>(N+1,false));
    dp[0][0] = true;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i > 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1])
                dp[i][j] = true;
            if (j > 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1])
                dp[i][j] = true;
        }
    }
    return dp[M][N];
}