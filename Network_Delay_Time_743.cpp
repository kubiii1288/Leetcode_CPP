//
// Created by Anh Le on 4/28/26.
//

#include <algorithm>

struct Edge
{
    int v, w;
};

int networkDelayTimeBellmanFord(vector<vector<int>>& times, int n, int k)
{
    const int INF = 1e9;
    vector<int> dist(n+1, INF);
    dist[k] = 0;
    for (int i = 1 ; i < n; i++)
    {
        for (vector<int> &v : times)
        {
            dist[v[1]] = min(dist[v[1]] ,dist[v[0]] + v[2]);
        }
    }
    int ans = *std::max_element(dist.begin()+1, dist.end());
    return ans == INF ? -1 : ans;
}

struct comp
{
    bool operator()(Edge &a, Edge &b) const
    {
        return a.w > b.w;
    }
};
int networkDelayTimeDijkstra(vector<vector<int>>& times, int n, int k) {
    const int INF = 1e9;
    vector<Edge> graph[n+1];
    for (vector<int> &v : times)
    {
        graph[v[0]].push_back({v[1],v[2]});
    }
    vector<int> dist(n+1, INF);
    priority_queue<Edge, vector<Edge>, comp> q;

    dist[k] = 0;
    q.push({k,0});
    while (!q.empty())
    {
        int u = q.top().v;
        int d = q.top().w;
        q.pop();
        if (d > dist[u]) continue;

        for (Edge &edge : graph[u])
        {
            if (dist[u] + edge.w < dist[edge.v])
            {
                dist[edge.v] = dist[u] + edge.w;
                q.push({edge.v, dist[edge.v]});
            }
        }
    }
    int ans = *max_element(dist.begin()+1, dist.end());
    return ans == INF ? -1 : ans;
}