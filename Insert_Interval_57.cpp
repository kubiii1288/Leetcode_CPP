//
// Created by Anh Le on 11/24/25.
//
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    intervals.insert(lower_bound(intervals.begin(),intervals.end(), newInterval), newInterval);
    pair<int,int> pointer = {intervals[0][0], intervals[0][1]};
    for (int i = 1; i < intervals.size(); i++)
    {
        if (pointer.first <= intervals[i][0] && intervals[i][0] <= pointer.second)
        {
            pointer.first = std::min(pointer.first, intervals[i][0]);
            pointer.second = std::max(pointer.second, intervals[i][1]);
        } else
        {
            ans.push_back({pointer.first, pointer.second});
            pointer = {intervals[i][0], intervals[i][1]};
        }
    }
    ans.push_back({pointer.first, pointer.second});
    return ans;
}