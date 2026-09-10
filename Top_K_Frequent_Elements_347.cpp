//
// Created by Anh Le on 6/3/26.
//
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int i : nums)
        freq[i]++;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    for (unordered_map<int,int>::iterator it = freq.begin(); it != freq.end(); it++)
    {
        q.push({it->second, it->first});
        if (q.size() > k)
            q.pop();
    }
    vector<int> ans;
    ans.reserve(k);
    while (!q.empty())
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}