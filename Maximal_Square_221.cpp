//
// Created by Anh Le on 4/29/26.
//
int maximalSquare(vector<vector<char>>& matrix)
{
    int best = 0;
    const int M = matrix.size();
    const int N = matrix[0].size();
    int dp[M][N];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = (matrix[i][j] == '1');
            best = max(best, dp[i][j]);
        }
    }
    if (best == 0)
        return best;
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (matrix[i][j] == '1' && matrix[i - 1][j] == '1' &&
                matrix[i][j - 1] == '1' && matrix[i - 1][j - 1] == '1')
            {
                dp[i][j] =
                    min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) +
                    1;
                best = max(best, dp[i][j]);
            }
        }
    }
    return best * best;
}
