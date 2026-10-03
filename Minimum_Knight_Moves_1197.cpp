//
// Created by Anh Le on 9/15/26.
//

int dx[8] = {1, -1, -2, -2, 1, -1, 2, 2};
int dy[8] = {2, 2, 1, -1, -2, -2, 1, -1};

struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        // A simple hash combination technique (such as boost::hash_combine)
        // to prevent collisions for common pairs like (1, 2) and (2, 1)
        return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) + 0x9e3779b9 + (std::hash<int>{}(p.first) << 6) + (std::hash<int>{}(p.second) >> 2));
    }
};
int minKnightMoves(int x, int y) {

    queue<pair<int,int>> q;
    unordered_set<pair<int,int>, PairHash> visited;
    visited.insert({0,0});
    q.push({0,0});

    int step = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size-->0)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == x && c == y) return step;
            for (int i = 0; i < 8; i++)
            {
                int xx = r + dx[i];
                int yy = c + dx[i];
                if ( -300 <= xx && xx <= 300 && -300 <= yy && yy <=300 && !visited.count({xx,yy}))
                {
                    visited.insert({xx,yy});
                    q.push({xx,yy});
                }
            }
        }
        step++;
    }
    return -1;
}