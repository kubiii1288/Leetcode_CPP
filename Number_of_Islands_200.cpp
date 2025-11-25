//
// Created by Anh Le on 11/12/25.
//
void dfs(vector<vector<char>> &graph, int x, int y, const int M, const int N)
{
    if (!(0 <= x && x < M && 0 <= y && y < N)) return;
    if (graph[x][y] == '0') return;

    graph[x][y] = '0';
    dfs(graph,x,y + 1,M,N);
    dfs(graph,x+1,y,M,N);
    dfs(graph,x,y-1,M,N);
    dfs(graph,x-1,y,M,N);
}

int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    // M rows, N columns
    const int M = grid.size();
    const int N = grid[0].size();
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                dfs(grid, i,j, M,N);
            }
        }
    }
    return ans;
}