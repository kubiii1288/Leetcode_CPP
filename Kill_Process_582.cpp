//
// Created by Anh Le on 9/11/26.
//
void dfs(unordered_map<int,vector<int>> &processes, vector<int> &deleted, int target)
{
    for (int child : processes[target])
        dfs(processes, deleted, child);
    deleted.push_back(target);
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    vector<int> ans;
    unordered_map<int,vector<int>> graph;
    for (int i = 0; i < ppid.size(); i++)
        graph[ppid[i]].push_back(pid[i]);

    dfs(graph, ans,kill);
    return ans;
}