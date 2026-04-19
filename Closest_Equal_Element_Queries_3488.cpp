
vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    const int size = nums.size();
    unordered_map<int,vector<int>> mp;
    for (int i = 0; i < size; i++)
    {
        mp[nums[i]].push_back(i);
    }

    vector<int> ans;
    ans.reserve(queries.size());
    vector<int> dp(size, INT_MAX);
    for (auto& [val,arr] : mp)
    {
        int k = arr.size();
        if (k ==1)
        {
            dp[arr.back()] = -1;
        } else
        {
            for (int i = 0; i < k; i++)
            {
                int current_index = arr[i];
                int next_index = arr[(i+1) %k];
                int prev_index = arr[(i-1 +k) % k];
                int d1 = abs(current_index-next_index);
                int d2 = abs(current_index-prev_index);
                dp[current_index] = min(min(d1,size-d1), min(d2, size-d2));
            }
        }
    }

    for (int q : queries)
    {
        ans.push_back(dp[q]);
    }

    return ans;
}