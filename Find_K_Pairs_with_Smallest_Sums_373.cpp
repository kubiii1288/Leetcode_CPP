//
// Created by Anh Le on 1/18/26.
//
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    set<pair<int,int>> s;
    pq.push({nums1[0] + nums2[0],{0,0}});
    s.insert({0,0});
    vector<vector<int>> ans;
    bool stop = false;
    while (k-->0 && !stop)
    {
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        ans.push_back({nums1[i],nums2[j]});

        stop = true;
        if (i + 1 < nums1.size())
        {
            stop = false;
            pair<int,int> temp = {i+1,j};
            if (s.find(temp) == s.end())
            {
                pq.push({nums1[temp.first] + nums2[temp.second], {temp.first,temp.second} });
                s.insert(temp);
            }
        }

        if (j + 1 < nums2.size())
        {
            stop = false;
            pair<int,int> temp = {i,j+1};
            if (s.find(temp) == s.end())
            {
                pq.push({nums1[temp.first] + nums2[temp.second], {temp.first,temp.second} });
                s.insert(temp);
            }
        }
    }
    return ans;
}