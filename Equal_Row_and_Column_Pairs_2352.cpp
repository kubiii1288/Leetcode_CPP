//
// Created by Anh Le on 8/9/26.
//
int equalPairs(vector<vector<int>>& grid) {
    const int N = grid.size();
    map<vector<int>, int> cnt;

    for (vector<int>& v : grid)
        cnt[v]++;
    int ans = 0;
    for (int c = 0; c < N; c++)
    {
        vector<int> arr;
        arr.reserve(N);
        for (int r = 0; r < N; r++)
            arr.push_back(grid[r][c]);

        ans += cnt[arr];
    }

    return ans;
}