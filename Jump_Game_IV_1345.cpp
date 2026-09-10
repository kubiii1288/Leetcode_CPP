//
// Created by Anh Le on 5/17/26.
//
int minJumps(vector<int>& arr)
{
    unordered_map<int, vector<int>> mp;
    const int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]].push_back(i);
    }
    vector<int> dist(size, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == size - 1)
            return dist[u];
        if (u + 1 < size && dist[u + 1] == -1)
        {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }

        if (u - 1 >= 0 && dist[u - 1] == -1)
        {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }

        for (int v : mp[arr[u]])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        mp[arr[u]].clear();
    }
    return dist[size - 1];
}
