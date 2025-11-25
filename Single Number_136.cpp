//
// Created by Anh Le on 10/10/25.
//
int singleNumber(vector<int>& nums) {
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}