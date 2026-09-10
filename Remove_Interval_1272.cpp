//
// Created by Anh Le on 8/31/26.
//

vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    int from = toBeRemoved[0];
    int to = toBeRemoved[1];

    vector<vector<int>> ans;
    ans.reserve(intervals.size());
    for (int i = 0; i < intervals.size(); i++)
    {
        if (from > intervals[i][1])
        {
            ans.push_back(intervals[i]);
        } else if (intervals[i][0] < from && from < intervals[i][1])
        {
            ans.push_back({intervals[i][0], from});
            if (to < intervals[i][1])
            {
                ans.push_back({to, intervals[i][1]});
            }
        } else if (from <= intervals[i][0])
        {
            if (to <= intervals[i][0])
            {
                ans.push_back(intervals[i]);
            } else if (to < intervals[i][1])
            {
                ans.push_back({to, intervals[i][1]});
            }
        }
    }
    return std::move(ans);
}

vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                      vector<int>& toBeRemoved) {
    int from = toBeRemoved[0];
    int to = toBeRemoved[1];

    vector<vector<int>> ans;
    ans.reserve(intervals.size());
    for (int i = 0; i < intervals.size(); i++) {

        if (from >= intervals[i][1] || to <= intervals[i][0]) {
            ans.push_back(std::move(intervals[i]));
            continue;
        }

        if (intervals[i][0] < from)
            ans.push_back({intervals[i][0], from});
        if (intervals[i][1] > to)
            ans.push_back({to, intervals[i][1]});
    }
    return std::move(ans);
}