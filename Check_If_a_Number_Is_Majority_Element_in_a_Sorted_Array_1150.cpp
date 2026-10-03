//
// Created by Anh Le on 9/23/26.
//
bool isMajorityElement(vector<int>& nums, int target) {
    int itemCount = (upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target));
    return itemCount > nums.size() / 2;
}