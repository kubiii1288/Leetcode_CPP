double bfs(unordered_map<string, vector<pair<string, double>>> &graph, string &start, string &end)
{
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) return -1;
    if (start == end) return 1;

    queue<pair<string,double>> q;
    unordered_set<string> visited;
    visited.insert(start);
    q.push({start,1.0});
    while (!q.empty())
    {
        pair<string, double> current = q.front();
        q.pop();
        if (current.first == end) return current.second;
        for (pair<string,double> &v  : graph[current.first])
        {
            if (visited.find(v.first) == visited.end())
            {
                visited.insert(v.first);
                q.push({v.first, current.second * v.second});
            }
        }
    }
    return -1;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> graph;
    for (int i= 0; i < equations.size(); i++)
    {
        graph[equations[i][0]].push_back({equations[i][1], values[i]});
        graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
    }

    vector<double> ans;
    for (vector<string> &q : queries)
    {
        ans.push_back(bfs(graph,q[0], q[1]));
    }
    return ans;
}