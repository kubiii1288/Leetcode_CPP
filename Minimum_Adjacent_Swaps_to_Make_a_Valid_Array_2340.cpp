//
// Created by kubiii on 10/21/26.
//

int minimumSwaps(vector<int>& nums) {
    int min_num = INT_MAX;
    int min_index = -1;
    int max_num = INT_MIN;
    int max_index = -1;
    for (int i = 0; i < nums.size();i++) {
        if (nums[i] < min_num) {
            min_num = nums[i];
            min_index = i;
        }
        if (nums[i] >= max_num) {
            max_num = nums[i];
            max_index=i;
        }
    }
    if (max_index < min_index) {
        return min_index + nums.size()-1 -max_index -1;
    }
    return min_index + nums.size() -1 - max_index;
}


int minimumSwaps_optimal(vector<int>& nums) {
    auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
    int ans = (min_it - nums.begin()) + (nums.end() -max_it -2);
    if (min_it > max_it)  ans--;
    return ans;
}