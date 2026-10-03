//
// Created by Anh Le on 9/14/26.
//
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    const int M = maze.size();
    const int N = maze[0].size();
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    maze[start[0]][start[1]] = -1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == destination[0] && y == destination[1]) return true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = x;
            int c = y;
            while (0 <= r + dx[i] && r +dx[i] < M && 0 <= c + dy[i] && c + dy[i] < N && maze[r+dx[i]][c+dy[i]] != 1)
            {
                r +=dx[i];
                c += dy[i];
            }
            if (maze[r][c] == 0)
            {
                maze[r][c] = -1;
                q.push({r,c});
            }
        }
    }
    return false;
}