//
// Created by Anh Le on 8/12/26.
//

void bfs(vector<vector<int>> &graph, vector<bool> &visited, int city)
{
    queue<int> q;
    q.push(city);
    visited[city] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < graph.size(); v++)
        {
            if (graph[u][v] && !visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    const int N = isConnected.size();
    vector<bool> visited(N,false);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            ans++;
            bfs(isConnected, visited, i);
        }
    }
    return ans;
}