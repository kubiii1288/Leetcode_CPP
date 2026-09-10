//
// Created by Anh Le on 5/5/26.
//
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int orangesRotting(vector<vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i,j});
            } else if (grid[i][j] == 1)
                fresh++;
        }
    }
    if (fresh == 0) return 0;
    int time = -1;
    while (!q.empty())
    {
        int size = q.size();
        while (size-->0)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (0 <= xx && xx < M && 0 <= yy && yy < N && grid[xx][yy] == 1)
                {
                    grid[xx][yy] = 2;
                    fresh--;
                    q.push({xx,yy});
                }
            }
        }
        time++;
    }
    return fresh == 0 ? time : -1;
}