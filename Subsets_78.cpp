//
// Created by Anh Le on 10/10/25.
//
void generate(vector<int>& arr, int size, vector<int>& nums,
                  vector<vector<int>>& sol) {
    if (arr.size() == size) {
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            if (arr[i] == 1)
                ans.push_back(nums[i]);
        }
        sol.push_back(ans);
        return;
    }

    arr.push_back(0);
    generate(arr, size, nums, sol);
    arr.pop_back();

    arr.push_back(1);
    generate(arr, size, nums, sol);
    arr.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> arr;
    vector<vector<int>> sol;
    generate(arr, nums.size(), nums, sol);
    return sol;
}