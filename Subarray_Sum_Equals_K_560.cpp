//
// Created by Anh Le on 6/2/26.
//
int subarraySum(vector<int>& nums, int k) {
    vector<int> dp(nums.size(),0);
    int size = nums.size();
    dp[0] = nums[0];
    for (int i = 1; i < size; i++)
    {
        dp[i] = nums[i] + dp[i-1];
    }
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (dp[j] - dp[i] + nums[i] == k)
                ans++;
        }
    }
    return ans;
}

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0] = 1;
    int sum = 0;
    int ans = 0;
    for (int i : nums)
    {
        sum += i;
        if (mp.count(sum - k))
            ans += mp[sum-k];
        mp[sum]++;
    }
    return ans;
}