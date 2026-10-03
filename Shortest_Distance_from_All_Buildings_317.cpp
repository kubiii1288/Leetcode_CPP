//
// Created by Anh Le on 9/13/26.
//
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int shortestDistance(vector<vector<int>>& grid)
{
    const int M = grid.size();
    const int N = grid[0].size();
    vector<vector<int>> distSum(M, vector<int>(N, 0));
    vector<vector<int>> reachCount(M, vector<int>(N, 0));
    int buildings = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1)
            {
                buildings++;
                queue<pair<int, int>> q;
                vector<vector<bool>> visited(M, vector<bool>(N, false));
                int dist = 0;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    int size = q.size();
                    dist++;
                    while (size-- > 0)
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            int xx = x + dx[i];
                            int yy = y + dy[i];
                            if (0 <= xx && xx < M && 0 <= yy && yy < N &&
                                grid[xx][yy] == 0 && !visited[xx][yy])
                            {
                                q.push({xx, yy});
                                visited[xx][yy] = true;
                                distSum[xx][yy] += dist;
                                reachCount[xx][yy]++;
                            }
                        }
                    }
                }
            }
        }
    }
    int minDist = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0 && reachCount[i][j] == buildings)
            {
                minDist = min(minDist, distSum[i][j]);
            }
        }
    }
    return minDist == INT_MAX ? -1 : minDist;
}
