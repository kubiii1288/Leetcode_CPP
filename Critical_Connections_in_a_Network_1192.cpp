//
// Created by Anh Le on 4/12/26.
//

void dfs(int u, vector<int> graph[], vector<int>& visited_at, vector<int>& low, vector<int>& parent,
         vector<vector<int>>& ans, int& time)
{
    visited_at[u] = low[u] = time++;
    for (int v : graph[u])
    {
        if (visited_at[v] == -1)
        {
            parent[v] = u;
            dfs(v, graph, visited_at, low, parent, ans, time);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > visited_at[u])
                ans.push_back({u, v});
        }
        else if (v != parent[u]) // v is visited and is not parent of u
            low[u] = std::min(low[u], visited_at[v]);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

    vector<int> graph[n];
    for (vector<int> &e : connections)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    vector<int> visited_at(n,-1);
    vector<int> parent(n,-1);
    vector<int> low(n,-1);
    vector<vector<int>> ans;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited_at[i] == -1)
        {
            dfs(i, graph, visited_at, low, parent, ans, time);
        }
    }
    return ans;
}