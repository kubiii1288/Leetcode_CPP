//
// Created by Anh Le on 1/24/26.
//
int lengthOfLIS(vector<int>& nums) {
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
            ans.push_back(nums[i]);
        else if (nums[i] < ans.back())
        {
            *lower_bound(ans.begin(), ans.end(),nums[i]) = nums[i];
        }
    }
    return ans.size();
}