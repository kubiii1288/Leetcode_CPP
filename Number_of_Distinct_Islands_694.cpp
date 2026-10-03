//
// Created by Anh Le on 9/12/26.
//

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void bfs(vector<vector<int>> &graph, const int M, const int N, int r, int c, set<vector<pair<int,int>>> &discover)
{
    queue<pair<int,int>> q;
    q.push({r,c});
    graph[r][c] = 0;
    vector<pair<int,int>> island;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        island.push_back({x-r, y-c});
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x +dx[i];
            int yy = y +dy[i];
            if (0 <= xx && xx < M && 0 <= yy && yy < N && graph[xx][yy] == 1)
            {
                graph[xx][yy] = 0;
                q.push({xx,yy});
            }
        }
    }
    discover.insert(island);
}
int numDistinctIslands(vector<vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();
    set<vector<pair<int,int>>> ans;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j])
            {
                bfs(grid, M, N, i,j,ans);
            }
        }
    }
    return ans.size();
}