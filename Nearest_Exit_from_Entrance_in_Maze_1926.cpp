//
// Created by Anh Le on 8/12/26.
//
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    const int M = maze.size();
    const int N = maze[0].size();
    const int INF = 1e9;
    vector<vector<bool>> visited(M, vector<bool>(N,false));
    vector<vector<int>> dist(M, vector<int>(N, INF));
    queue<pair<int,int>> q;
    int R = entrance[0], C = entrance[1];
    q.push({R,C});
    visited[R][C] = true;
    dist[R][C] = 0;

    int ans = INF;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == 0 || x == M-1 || y == 0 || y == N-1)
        {
            if (x != R || y != C)
                ans = min(ans, dist[x][y]);
        }

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (0 <= xx && xx < M && 0 <= yy && yy < N && maze[xx][yy] == '.' && !visited[xx][yy])
            {
                visited[xx][yy] = true;
                dist[xx][yy] = dist[x][y] +1;
                q.push({xx,yy});
            }
        }
    }
    return ans != INF ? ans : -1;
}

