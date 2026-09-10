//
// Created by Anh Le on 8/11/26.
//
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    const size_t N = rooms.size();
    unordered_set<int> visited;
    queue<int> q;
    q.push(0);
    visited.insert(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : rooms[u])
        {
            if (visited.count(v) == 0)
            {
                visited.insert(v);
                q.push(v);
            }
        }
    }
    return visited.size() == N;
}