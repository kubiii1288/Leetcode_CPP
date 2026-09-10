//
// Created by Anh Le on 8/29/26.
//
vector<vector<int>> multiply(vector<vector<int>>& mat1,
                                vector<vector<int>>& mat2) {
    const int M = mat1.size();
    const int R = mat1[0].size();
    const int N = mat2[0].size();

    vector<vector<int>> ans(M, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        for (int k = 0; k < R; k++) {
            if (mat1[i][k] == 0) continue;
            for (int j = 0; j < N; j++) {
                ans[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    return std::move(ans);
}