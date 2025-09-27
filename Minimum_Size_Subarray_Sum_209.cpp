//
// Created by Anh Le on 9/27/25.
//
int minSubArrayLen(int target, vector<int>& nums)
{
    int left, right;
    left = right = 0;
    int sum = 0;
    int ans = INT_MAX;
    while (right < nums.size())
    {
        sum += nums[right];
        while (sum >= target)
        {
            ans = std::min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return (ans == INT_MAX) ? 0 : ans;
}
