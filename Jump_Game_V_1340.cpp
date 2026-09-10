//
// Created by Anh Le on 5/24/26.
//
int dfs(int i, vector<int>& dp, vector<int>& arr, int d) {
    if (dp[i] != -1)
        return dp[i];
    int best = 1;
    // go right
    for (int step = 1; step <= d && i + step < arr.size(); step++) {
        if (arr[i] <= arr[i + step])
            break;
        best = max(best, 1 + dfs(i + step, dp, arr, d));
    }
    // go left
    for (int step = 1; step <= d && i - step >= 0; step++) {
        if (arr[i] <= arr[i - step])
            break;
        best = max(best, 1 + dfs(i - step, dp, arr, d));
    }
    return dp[i] = best;
}
int maxJumps(vector<int>& arr, int d) {
    vector<int> dp(arr.size(), -1);
    int ans = 1;
    for (int i = 0; i < arr.size(); i++) {
        ans = max(ans, dfs(i, dp, arr, d));
    }
    return ans;
}