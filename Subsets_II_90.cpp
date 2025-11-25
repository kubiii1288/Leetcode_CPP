//
// Created by Anh Le on 11/8/25.
//
void solve(vector<vector<int>>& ans, vector<int>& current,
               vector<int>& nums, int index) {
    if (index == nums.size()) {
        ans.push_back(current);
        return;
    }
    current.push_back(nums[index]);
    solve(ans, current, nums, index + 1);
    current.pop_back();

    while (index + 1 < nums.size() && nums[index] == nums[index + 1])
        index++;
    solve(ans, current, nums, index + 1);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> current;
    solve(ans, current, nums, 0);
    return ans;
}