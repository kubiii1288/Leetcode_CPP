void solve(vector<vector<int>>& ans, vector<int>& sol, vector<int>& arr,
int size, int target, int current_sum, int index) {
    if (current_sum == target) {
        ans.push_back(sol);
        return;
    }

    for (int i = index; i < size; i++) {
        if (current_sum + arr[i] <= target) {
            sol.push_back(arr[i]);
            solve(ans, sol, arr, size, target, current_sum + arr[i], i);
            sol.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sol;
    solve(ans, sol, candidates, candidates.size(), target, 0, 0);
    return ans;
}