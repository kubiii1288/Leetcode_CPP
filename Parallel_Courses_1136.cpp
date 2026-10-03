//
// Created by Anh Le on 9/12/26.
//

int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> graph(n+1);
    vector<int> inDegree(n+1);
    for (vector<int> &v : relations)
    {
        graph[v[0]].push_back(v[1]);
        inDegree[v[1]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    int semesters = 0;
    int finished = 0;
    while (!q.empty())
    {
        semesters++;
        int size = q.size();
        while (size-->0)
        {
            int prev = q.front();
            q.pop();
            finished++;
            for (int next : graph[prev])
            {
                inDegree[next]--;
                if (inDegree[next] == 0)
                    q.push(next);
            }
        }
    }
    return finished == n ? semesters : -1;
}