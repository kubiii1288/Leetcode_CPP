//
// Created by Anh Le on 5/3/26.
//
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
{
    vector<int> graph[n + 1];
    vector<int> in_degree(n + 1, 0);
    for (vector<int> r : relations)
    {
        int u = r[0];
        int v = r[1];
        graph[u].push_back(v);
        in_degree[v]++;
    }
    vector<int> dp(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
            dp[i] = time[i - 1];
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            dp[v] = max(dp[v], dp[u] + time[v - 1]);
            if (--in_degree[v] == 0)
                q.push(v);
        }
    }
    return *max_element(dp.begin() + 1, dp.end());
}
