//
// Created by Anh Le on 4/14/26.
//
struct node
{
    int v, w;
};

struct comp
{
    bool operator()(const node& a, const node &b) const
    {
        return a.w > b.w;
    }
};
int minCostConnectPoints(vector<vector<int>>& points) {
    vector<node> graph[points.size()];
    vector<int> dist(points.size(), INT_MAX);
    vector<bool> visited(points.size(), false);
    priority_queue<node, vector<node>, comp> pq;
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i +1; j < points.size(); j++)
        {
            int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            graph[i].push_back({j,w});
            graph[j].push_back({i,w});
        }
    }

    dist[0] = 0;
    pq.push({0,0});
    while (!pq.empty())
    {
        int u = pq.top().v;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        for (node& neighbor : graph[u])
        {
            if (!visited[neighbor.v] && neighbor.w < dist[neighbor.v])
            {
                dist[neighbor.v] = neighbor.w;
                pq.push(neighbor);
            }
        }
    }

    int cost = 0;
    for (int i = 0; i < points.size(); i++)
    {
        cost += dist[i];
    }
    return cost;
}