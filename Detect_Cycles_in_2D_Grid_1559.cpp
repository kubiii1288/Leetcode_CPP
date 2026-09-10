//
// Created by Anh Le on 4/25/26.
//
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool dfs(int r, int c, int pr, int pc, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    visited[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int xx = r + dx[i];
        int yy = c + dy[i];
        if (0 <= xx && xx < N  && 0 <= yy && yy < M && grid[xx][yy] == grid[r][c])
        {
            if (xx == pr && yy == pc) continue;
            if (visited[xx][yy]) return true;
            if (dfs(xx,yy, r,c, grid, visited))
                return true;
        }
    }
    return false;
}
bool containsCycle(vector<vector<char>>& grid) {
    N = grid.size();
    M = grid.back().size();
    vector<vector<bool>> check(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!check[i][j] && dfs(i,j, -1,-1, grid, check))
                return true;
        }
    }
    return false;
}