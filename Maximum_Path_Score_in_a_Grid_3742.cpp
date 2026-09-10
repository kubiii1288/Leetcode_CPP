//
// Created by Anh Le on 4/30/26.
//
int maxPathScore(vector<vector<int>>& grid, int k)
{
    const int M = grid.size();
    const int N = grid[0].size();
    int K = k;
    int dp[M][N][K + 1];
    fill_n(&dp[0][0][0], M * N * (K + 1), INT_MIN);
    dp[0][0][0] = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int c = 0; c <= K; c++)
            {
                if (dp[i][j][c] == INT_MIN) continue;
                if (i + 1 < M)
                {
                    int value = grid[i + 1][j];
                    int cost = (value != 0);
                    int newCost = c + cost;
                    if (newCost <= K)
                    {
                        dp[i + 1][j][newCost] = max(dp[i + 1][j][newCost], dp[i][j][c] + value);
                    }
                }
                if (j + 1 < N)
                {
                    int value = grid[i][j + 1];
                    int cost = (value != 0);
                    int newCost = c + cost;
                    if (newCost <= K)
                    {
                        dp[i][j + 1][newCost] = max(dp[i][j + 1][newCost], dp[i][j][c] + value);
                    }
                }
            }
        }
    }
    int ans = INT_MIN;
    for (int c = 0; c <= K; c++)
    {
        ans = max(ans, dp[M - 1][N - 1][c]);
    }
    return ans == INT_MIN ? -1 : ans;
}
