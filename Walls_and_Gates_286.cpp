//
// Created by Anh Le on 9/15/26.
//

#define INF 2147483647
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void wallsAndGates(vector<vector<int>>& rooms)
{
    const int M = rooms.size();
    const int N = rooms[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (rooms[i][j] == 0)
                q.push({i, j});

    int distance = 0;
    while (!q.empty())
    {
        int size = q.size();
        distance++;
        while (size-- > 0)
        {
            auto [r,c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = r + dx[i];
                int yy = c + dx[i];
                if (0 <= xx && r < M && 0 <= yy && yy < N && rooms[xx][yy] == INF)
                {
                    rooms[xx][yy] = distance;
                    q.push({xx, yy});
                }
            }
        }
    }
}