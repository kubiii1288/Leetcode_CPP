//
// Created by Anh Le on 1/26/26.
//
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid.back().size();

    obstacleGrid[0][0] = (obstacleGrid[0][0] ? 0 : 1);
    for (int i = 1; i < m; i++)
        obstacleGrid[i][0] = (obstacleGrid[i][0] ? 0 : obstacleGrid[i-1][0]);
    for (int i = 1; i < n; i++)
        obstacleGrid[0][i] = (obstacleGrid[0][i] ? 0 : obstacleGrid[0][i-1]);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            obstacleGrid[i][j] = (obstacleGrid[i][j] ? 0 : (obstacleGrid[i][j-1] + obstacleGrid[i-1][j]));
    return obstacleGrid.back().back();
}