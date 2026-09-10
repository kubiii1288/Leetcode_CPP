//
// Created by Anh Le on 8/12/26.
//

int minReorder(int n, vector<vector<int>>& connections) {
    vector<bool> visited(n, false);
    set<vector<int>> roads(connections.begin(), connections.end());
    vector<vector<int>> graph(n);
    for (vector<int> &edge : connections)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    queue<int> q;
    visited[0] = true;
    q.push(0);
    int changes = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                if (roads.count({v,u}) == 0)
                    changes++;
                q.push(v);
            }
        }
    }
    return changes;
}