//
// Created by Anh Le on 4/27/26.
//
pair<int, int> up_d = {-1, 0};
pair<int, int> down_d = {1, 0};
pair<int, int> left_d = {0, -1};
pair<int, int> right_d = {0, 1};

unordered_map<int, vector<pair<int, int>>> dirs = {
    {1, {left_d, right_d}}, {2, {up_d, down_d}}, {3, {left_d, down_d}},
    {4, {right_d, down_d}}, {5, {up_d, left_d}}, {6, {up_d, right_d}}
};
int M, N;

bool canGo(int r, int c, int nr, int nc, vector<vector<int>>& grid)
{
    int next = grid[nr][nc];
    pair<int, int> rev_d = {r - nr, c - nc};
    if (find(dirs[next].begin(), dirs[next].end(), rev_d) ==
        dirs[next].end())
        return false;
    return true;
}

bool dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& grid)
{
    visited[r][c] = true;
    if (r == M - 1 && c == N - 1)
        return true;
    for (pair<int, int>& dir : dirs[grid[r][c]])
    {
        int xx = r + dir.first;
        int yy = c + dir.second;
        if (0 <= xx && xx < M && 0 <= yy && yy < N && !visited[xx][yy] &&
            canGo(r, c, xx, yy, grid))
            if (dfs(xx, yy, visited, grid))
                return true;
    }
    return false;
}

bool hasValidPath(vector<vector<int>>& grid)
{
    M = grid.size();
    N = grid.back().size();
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    return dfs(0, 0, visited, grid);
}
