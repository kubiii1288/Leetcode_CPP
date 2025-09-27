//
// Created by Anh Le on 9/26/25.
//
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int i, left, right;
    i = 0;
    while (i < nums.size() - 2)
    {
        if (nums[i] > 0)
            break;
        left = i + 1;
        right = nums.size() - 1;
        while (left < right)
        {
            int current_sum = nums[i] + nums[left] + nums[right];
            if (current_sum == 0)
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                while (left < nums.size() - 1 &&
                    nums[left] == nums[left + 1])
                {
                    left++;
                }
            }

            if (current_sum > 0)
            {
                right--;
            }
            else
                left++;
        }
        while (i < nums.size() - 2 && nums[i] == nums[++i]);
    }
    return ans;
}
