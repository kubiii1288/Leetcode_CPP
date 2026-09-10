//
// Created by Anh Le on 4/28/26.
//
void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans ,vector<int> &path, int current, int dest)
{
    path.push_back(current);
    if (current == dest)
    {
        ans.push_back(path);
        path.pop_back();
        return;
    }
    for (int next : graph[current])
    {
        dfs(graph, ans, path, next, dest);
    }
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(graph, ans, path, 0, graph.size()-1);
    return std::move(ans);
}
