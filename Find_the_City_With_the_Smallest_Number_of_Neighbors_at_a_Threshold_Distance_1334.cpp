//
// Created by Anh Le on 5/2/26.
//
const int INF = 1e9;
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n,INF));
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (vector<int> &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if (w <= distanceThreshold)
        {
            dist[u][v] =  w;
            dist[v][u] =  w;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<int> count(n,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] <= distanceThreshold)
            {
                count[i]++;
            }
        }
        cout << endl;
    }
    int ans = 0;
    int min_reachable = count[0];
    for (int i = 1; i < n; i++)
    {
        if (count[i] <= min_reachable)
        {
            min_reachable = count[i];
            ans = i;
        }
    }
    return ans;
}