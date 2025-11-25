//
// Created by Anh Le on 11/8/25.
//
void solve(vector<vector<int>> &ans, vector<int> &current, vector<int> &numbs, int index, int size, int target)
{
    if (target < 0) return;
    if (0 == target)
    {
        ans.push_back(current);
        return;
    }
    for (int i = index; i < size ; i++)
    {
        if (i == index || numbs[i] != numbs[i-1])
        {
            current.push_back(numbs[i]);
            solve(ans,current, numbs, i + 1, size, target - numbs[i]);
            current.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;

    sort(candidates.begin(), candidates.end());
    solve(ans, current, candidates, 0, candidates.size(), target);
    return ans;
}