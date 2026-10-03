//
// Created by Anh Le on 9/14/26.
//

struct node
{
    int distance, r, c;
};
struct CompareNode
{

    bool operator() (const node& a, const node& b) const
    {
        return a.distance > b.distance;
    }
};
int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    const int M = maze.size();
    const int N = maze[0].size();
    priority_queue<node, vector<node>, CompareNode> q;
    q.push({0,start[0], start[1]});
    vector<vector<int>> dist(M, vector<int>(N,1e9));
    dist[start[0]][start[1]] = 0;
    while (!q.empty())
    {
        int distance = q.top().distance;
        int r = q.top().r;
        int c = q.top().c;
        q.pop();
        if (distance > dist[r][c]) continue;
        if (r == destination[0] && c == destination[1]) return dist[r][c];

        for (int i = 0; i < 4; i++)
        {
            int x = r;
            int y = c;
            int d = 0;
            while (0 <= x + dx[i] && x + dx[i] < M && 0 <= y + dy[i] && y + dy[i] < N && maze[x+dx[i]][y + dy[i]] != 1)
            {
                d++;
                x += dx[i];
                y += dy[i];
            }
            if (distance + d < dist[x][y])
            {
                dist[x][y] = distance + d;
                q.push({dist[x][y], x,y});
            }
        }
    }
    return -1;
}