//
// Created by Anh Le on 11/4/25.
//
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> hash_map;
    for (int i = 0; i < nums.size(); i++) {
        unordered_map<int, int>::iterator it = hash_map.find(nums[i]);
        if (it != hash_map.end() && abs(i - it->second) <= k)
            return true;

        hash_map[nums[i]] = i;
    }
    return false;
}