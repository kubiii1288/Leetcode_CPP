//
// Created by Anh Le on 8/23/26.
//
int maxDistance(vector<vector<int>>& arrays) {
    int low = arrays[0][0];
    int high = arrays[0].back();
    int ans = 0;
    for (int i = 1; i < arrays.size(); i++)
    {
        ans = max({ans, arrays[i].back() - low, high - arrays[i][0]});
        low = min(low, arrays[i][0]);
        high = max(high, arrays[i].back());
    }
    return ans;
}

