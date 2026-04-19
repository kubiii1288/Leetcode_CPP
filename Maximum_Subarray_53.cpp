//
// Created by Anh Le on 2/15/26.
//
int maximum_subarray(vector<int>& nums, int low, int high)
{
    if (high - low == 1) return nums[low];
    int mid = (low + high) / 2;
    int max_left = maximum_subarray(nums, low, mid);
    int max_right = maximum_subarray(nums, mid, high);
    int sum_left = 0, sum_right = 0;
    int best_left = INT_MIN, best_right = INT_MIN;
    for (int i = mid - 1; i >= low; i--)
    {
        sum_left += nums[i];
        best_left = max(best_left, sum_left);
    }
    for (int i = mid; i < high; i++)
    {
        sum_right += nums[i];
        best_right = max(best_right, sum_right);
    }
    return max(max_left, max(max_right, best_left + best_right));
}

int maxSubArray(vector<int>& nums)
{
    return maximum_subarray(nums, 0, nums.size());
}/