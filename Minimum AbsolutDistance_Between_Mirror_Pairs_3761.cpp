int reverse(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

int minMirrorPairDistance(vector<int>& nums)
{
    unordered_map<int, int> mp;
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        unordered_map<int, int>::iterator it = mp.find(nums[i]);
        if (it != mp.end())
        {
            ans = min(ans, i - it->second);
        }
        mp[reverse(nums[i])] = i;
    }
    return ans == INT_MAX ? -1 : ans;
}
