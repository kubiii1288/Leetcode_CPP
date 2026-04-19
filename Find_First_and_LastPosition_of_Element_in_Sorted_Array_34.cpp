//
// Created by Anh Le on 11/26/25.
//
vector<int> searchRange(vector<int>& nums, int target)
{
    if (binary_search(nums.begin(), nums.end(),target) == 0) return {-1,-1};
    int first = lower_bound(nums.begin(), nums.end(),target) - nums.begin();
    int second = upper_bound(nums.begin(), nums.end(),target) - nums.begin() -1;
    return {first, second};
}