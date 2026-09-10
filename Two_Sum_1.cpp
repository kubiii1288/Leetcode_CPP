//
// Created by Anh Le on 6/2/26.
//
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(target - nums[i])) {
            return {i, mp[target - nums[i]]};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}