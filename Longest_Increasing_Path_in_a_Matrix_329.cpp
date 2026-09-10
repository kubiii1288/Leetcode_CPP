//
// Created by Anh Le on 5/3/26.
//
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int M, N;

int dfs(int r, int c, vector<vector<int>>& matrix,
        vector<vector<int>>& dp)
{
    if (dp[r][c] != -1)
        return dp[r][c];
    dp[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = r + dx[i];
        int yy = c + dy[i];
        if (0 <= xx && xx < M && 0 <= yy && yy < N &&
            matrix[xx][yy] > matrix[r][c])
        {
            dp[r][c] = max(dp[r][c], 1 + dfs(xx, yy, matrix, dp));
        }
    }
    return dp[r][c];
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    M = matrix.size();
    N = matrix[0].size();
    int best = -1;
    vector<vector<int>> dp(M, vector<int>(N, -1));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            best = max(best, dfs(i, j, matrix, dp));
        }
    }
    return best;
}
