//
// Created by Anh Le on 5/1/26.
//
int rob(vector<int>& nums) {
    if (nums.size() <= 3) return *max_element(nums.begin(), nums.end());
    const int n = nums.size();
    vector<int> dp(n,-1);
    // Case 1: 0 -> n-2
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i <= n-2; i++)
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    int best_1 = dp[n-2];
    // Case 2: 1 -> n-1;
    dp[1] = nums[1];
    dp[2] = max(nums[2], nums[1]);
    for (int i = 3; i <= n-1; i++)
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    int best_2 = dp[n-1];
    return max(best_1, best_2);
}