//
// Created by Anh Le on 9/11/26.
//
bool dfs(vector<int> &visited, vector<vector<int>> &graph, int src, int dst)
{
    if (visited[src] == 1) return false;
    if (visited[src] == 2) return true;
    if (graph[src].empty())
        return src == dst;
    visited[src] = 1;
    for (int v : graph[src])
    {
        if (!dfs(visited, graph, v, dst))
                return false;
    }
    visited[src] = 2;
    return true;
}

bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n);
    for (vector<int> e : edges)
        graph[e[0]].push_back(e[1]);
    vector<int> visited(n,0);
    return dfs(visited, graph, source,destination);
}