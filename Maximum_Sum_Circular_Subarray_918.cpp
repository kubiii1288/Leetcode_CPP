//
// Created by Anh Le on 4/29/26.
//
int maxSubarraySumCircular(vector<int>& nums) {

    int max_sum = -1e9;
    int min_sum= 1e9;
    int min_end_at_i = 1e9;
    int max_end_at_i = -1e9;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        max_end_at_i = max(nums[i], max_end_at_i + nums[i]);
        max_sum = max(max_end_at_i, max_sum);
        min_end_at_i = min(nums[i], min_end_at_i + nums[i]);
        min_sum = min(min_sum, min_end_at_i);
    }
    if (max_sum < 0) return max_sum;
    return max(max_sum, sum - min_sum);
}