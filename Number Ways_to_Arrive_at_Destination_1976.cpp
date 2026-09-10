//
// Created by Anh Le on 5/2/26.
//
const int MOD = 1e9 + 7;

struct Vertex
{
    int v;
    long long w;
};
struct comp
{
    bool operator()(const Vertex &a, const Vertex &b) const
    {
        return a.w > b.w;
    }
};
int countPaths(int n, vector<vector<int>>& roads) {
    vector<Vertex> graph[n];
    for (vector<int> &v : roads)
    {
        graph[v[0]].push_back({v[1],(long long)v[2]});
        graph[v[1]].push_back({v[0],(long long )v[2]});
    }
    vector<long long> dist(n, LLONG_MAX);
    vector<int> way(n,0);
    priority_queue<Vertex,vector<Vertex>, comp> q;
    q.push({0,0});
    dist[0] = 0;
    way[0] = 1;
    while (!q.empty())
    {
        int current = q.top().v;
        long long cost = q.top().w;
        q.pop();
        if (cost > dist[current]) continue;
        for (Vertex &neighbor : graph[current])
        {
            int v = neighbor.v;
            long long w = neighbor.w;
            if (dist[current] + w < dist[v])
            {
                way[v] = way[current];
                dist[v] = dist[current] + w;
                q.push({v, dist[v]});
            } else if (dist[current] + w == dist[v])
            {
                way[v] = (way[v] + way[current]) % MOD;
            }
        }
    }
    return way[n-1];
}
