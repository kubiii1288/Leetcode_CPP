//
// Created by Anh Le on 10/21/25.
//
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    do {
        ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
}