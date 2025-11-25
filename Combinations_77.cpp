//
// Created by Anh Le on 10/17/25.
//
void generate(int n, int k, int current, vector<int>& sol,
                  vector<vector<int>>& ans) {
    if (sol.size() == k) {
        ans.push_back(sol);
        return;
    }
    for (int i = current; i <= n; i++) {
        sol.push_back(i);
        generate(n, k, i + 1, sol, ans);
        sol.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> sol;
    generate(n, k, 1, sol, ans);
    return ans;
}