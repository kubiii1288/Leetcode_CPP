//
// Created by Anh Le on 11/24/25.
//
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<vector<int>> ans;
    for (vector<int> &v : intervals)
    {
        q.push({v.at(0), v.at(1)});
    }
    pair<int,int> pointer = q.top();
    q.pop();
    while (!q.empty())
    {
        pair<int,int> top = q.top(); q.pop();
        if (pointer.first <= top.first && top.first <= pointer.second)
        {
            pointer.first = std::min(pointer.first, top.first);
            pointer.second = std::max(pointer.second, top.second);
        } else
        {
            ans.push_back({pointer.first, pointer.second});
            pointer = top;
        }
    }
    ans.push_back({pointer.first, pointer.second});
    return ans;
}