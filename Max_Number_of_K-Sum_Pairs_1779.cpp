//
// Created by Anh Le on 8/7/26.
//
int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size()-1;
    int ans = 0;
    while (l < r)
    {
        int sum = nums[l] +  nums[r];
        if (sum == k)
        {
            ans++;
            r--;
            l++;
        }
        else if (sum > k)
            r--;
        else l++;
    }
    return ans;
}