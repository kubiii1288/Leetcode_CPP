//
// Created by Anh Le on 4/28/26.
//
int findCheapestPriceBellmanFord(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    const int INF = 1e9;
    vector<int> dist(n,INF);
    dist[src] = 0;
    for(int i = 0; i <= k; i++)
    {
        vector<int> temp = dist;
        for(vector<int> &v : flights)
        {
            if (dist[v[0]] != INF)
            {
                temp[v[1]] = min(temp[v[1]], dist[v[0]] + v[2]);
            }
        }
        dist = std::move(temp);
    }
    return dist[dst] == INF ? -1 : dist[dst];
}
struct Edge
{
    int city, cost,stop;
};

struct comp
{
    bool operator() (const Edge &a, const Edge &b) const
    {
        return a.cost > b.cost;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(k+2, INF));
    vector<Edge> graph[n];
    for (vector<int> &v : flights)
        graph[v[0]].push_back({v[1],v[2], 0});

    priority_queue<Edge, vector<Edge>, comp> q;
    dist[src][0] = 0;
    q.push({src,0,0});
    while (!q.empty())
    {
        int u = q.top().city;
        int cost = q.top().cost;
        int stops = q.top().stop;
        q.pop();

        if (u == dst) return cost;
        if (stops > k) continue;
        for (Edge &edge : graph[u])
        {
            int newCost = cost + edge.cost;
            if (newCost < dist[edge.city][stops+1])
            {
                dist[edge.city][stops+1] = newCost;
                q.push({edge.city, newCost, stops+1});
            }
        }
    }
    return -1;
}