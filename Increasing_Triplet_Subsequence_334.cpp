//
// Created by Anh Le on 7/31/26.
//
bool increasingTriplet(vector<int>& nums) {
    vector<int> arr;
    arr.reserve(nums.size());
    arr.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > arr.back())
            arr.push_back(nums[i]);
        else
            *lower_bound(arr.begin(), arr.end(), nums[i]) = nums[i];
    }
    return arr.size() >= 3;
}