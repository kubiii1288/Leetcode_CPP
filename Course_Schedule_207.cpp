bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> inDegree(numCourses,0);
    for (vector<int> &edge : prerequisites)
    {
        graph[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i]== 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for (int v : graph[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }
    return ans.size() == numCourses;
}
