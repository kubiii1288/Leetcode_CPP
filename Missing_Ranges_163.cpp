//
// Created by Anh Le on 8/30/26.
//

vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > lower)
        {
            ans.push_back({lower, nums[i]-1});
        }
        lower = nums[i] +1;
    }
    if (lower <= upper)
        ans.push_back({lower,upper});
    return ans;
}