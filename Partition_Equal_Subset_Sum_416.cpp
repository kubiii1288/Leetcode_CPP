//
// Created by Anh Le on 5/17/26.
//
bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(),nums.end(), 0);
    if (sum % 2) return false;
    int target = sum /2;
    vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, 0));
    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i-1])
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - nums[i-1]] + nums[i-1]);
            }
        }
    }
    return dp.back().back() == target;
}