//
// Created by Anh Le on 4/30/26.
//
int M, N;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int ans = 0;

void dfs(int r, int c, vector<vector<int>>& grid, int& ceilLeft)
{
    if (grid[r][c] == 2)
    {
        if (ceilLeft == 1)
            ans++;
        return;
    }
    grid[r][c] = 1;
    ceilLeft--;
    for (int i = 0; i < 4; i++)
    {
        int x = r + dr[i];
        int y = c + dc[i];
        if (0 <= x && x < M && 0 <= y && y < N && grid[x][y] != 1 && grid[x][y] != -1)
        {
            dfs(x, y, grid, ceilLeft);
        }
    }
    ceilLeft++;
    grid[r][c] = 0;
}

int uniquePathsIII(vector<vector<int>>& grid)
{
    M = grid.size();
    N = grid[0].size();
    int ceilLeft = 0;
    int start_r, start_c;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] != -1)
            {
                ceilLeft++;
                if (grid[i][j] == 1)
                {
                    start_r = i;
                    start_c = j;
                }
            }
        }
    }
    dfs(start_r, start_c, grid, ceilLeft);
    return ans;
}
