//
// Created by Anh Le on 5/2/26.
//
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    const int size = numCourses;
    vector<vector<int>> dist(size, vector<int>(size, INF));
    for (int i = 0; i < size; i++)
        dist[i][i] = 0;

    for (vector<int> &e : prerequisites)
    {
        int u = e[0];
        int v = e[1];
        dist[u][v] = 1;
    }
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (dist[i][k] != INF)
                    dist[i][j] = min(dist[i][j],  dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<bool> ans;
    for (vector<int> &q : queries)
    {
        int u = q[0];
        int v = q[1];
        ans.push_back((dist[u][v] != INF));
    }
    return std::move(ans);
}