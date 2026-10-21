//
// Created by kubiii on 10/18/26.
//

vector<int> getMinExclude(vector<int> &v) {
    vector<int> ans(v.size());
    int minCost = INT_MAX;
    int secondMinCost = INT_MAX;
    int duplicate = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < minCost) {
            secondMinCost = minCost;
            minCost = v[i];
            duplicate = 0;
        } else if (v[i] == minCost) {
            duplicate++;
        } else if (v[i] < secondMinCost) {
            secondMinCost = v[i];
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (v[i] == minCost) {
            ans[i] = duplicate ? minCost : secondMinCost;
        } else ans[i] =minCost;
    }
    return ans;
}
int minCostII(vector<vector<int>>& costs) {
    const int n = costs.size();
    const int k = costs[0].size();
    for (int i = 1; i < n; i++) {
        vector<int> previous = getMinExclude(costs[i-1]);
        for (int j = 0; j < k; j++) {
            costs[i][j] += previous[j];
        }
    }
    return *std::min_element(costs.back().begin(), costs.back().end());
}