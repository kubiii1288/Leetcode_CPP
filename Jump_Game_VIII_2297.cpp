//
// Created by kubiii on 10/22/26.
//

long long minCost(vector<int>& nums, vector<int>& costs) {
    const int n = nums.size();
    vector<int> dec;
    dec.reserve(n);
    vector<int> inc;
    inc.reserve(n);
    vector<long long> dp(n,LLONG_MAX);
    dp[-1] = 0;
    for (int i = -1; i < n; i++) {
        while (!dec.empty() && nums[dec.back()] <= nums[i]) {
            int back = dec.back();
            dec.pop_back();
            dp[i] = min(dp[i], dp[back] + costs[i]);
        }
        while (!inc.empty() && nums[inc.back()] > nums[i]) {
            int back = inc.back();
            inc.pop_back();
            dp[i] = min(dp[i], dp[back] + costs[i]);
        }
        dec.push_back(i);
        inc.push_back(i);
    }
    return dp.back();
}
