//
// Created by Anh Le on 9/14/26.
//

struct node
{
    int cost;
    string path;
    int r;
    int c;
};
struct comparator
{
    bool operator() (const node &a, const node& b) const
    {
        if (a.cost == b.cost)
            return a.path > b.path;
        return a.cost > b.cost;
    }
};

string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
    unordered_map<char, pair<int,int>> directions;
    directions.insert({'l', {0,-1}});
    directions.insert({'r', {0,1}});
    directions.insert({'u', {-1,0}});
    directions.insert({'d', {1,0}});
    const int M = maze.size();
    const int N = maze[0].size();
    priority_queue<node, vector<node>, comparator> q;
    vector<vector<int>> dist(M, vector<int> (N, 1e9));
    vector<vector<string>> bestPath(M, vector<string>(N));
    dist[ball[0]][ball[1]] = 0;
    bestPath[ball[0]][ball[1]] = "";
    q.push({0, "", ball[0], ball[1]});
    while (!q.empty())
    {
        node front = q.top();
        q.pop();
        int cost = front.cost;
        string path = front.path;
        int row = front.r;
        int col = front.c;
        if (cost > dist[row][col]) continue;
        if (row == hole[0] && col == hole[1]) return path;
        for (unordered_map<char, pair<int,int>>::iterator it = directions.begin(); it != directions.end(); ++it)
        {
            int d = 0;
            int x = row;
            int y = col;
            int dx = it->second.first;
            int dy = it->second.second;
            char dir = it->first;
            while (0 <= x + dx && x + dx < M && 0 <= y + dy && y + dy < N && maze[x + dx][y + dy] != 1)
            {
                d++;
                x += dx;
                y += dy;
                if (x == hole[0] && y == hole[1]) break;
            }
            string newPath = path + dir;
            if (cost + d < dist[x][y] || (cost + d == dist[x][y] && newPath < bestPath[x][y]))
            {
                dist[x][y] = cost + d;
                bestPath[x][y] = newPath;
                q.push({dist[x][y], newPath, x,y });
            }
        }
    }
    return "impossible";
}