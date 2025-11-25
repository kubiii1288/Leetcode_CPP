//
// Created by Anh Le on 11/24/25.
//
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;

    int first = 0;
    int last = 0;
    while (first < nums.size())
    {
        while (last +1 < nums.size() && nums[last + 1] == nums[last] + 1)
        {
            last++;
        }
        if (nums[first] == nums[last])
        {
            ans.push_back(to_string(nums[first]));
        } else
        {
            ans.push_back(to_string(nums[first]) + "->" + to_string(nums[last]));
        }
        first = ++last;
    }
    return ans;
}