//
// Created by Anh Le on 10/5/25.
//
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<pair<int, int>> mask;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0)
                mask.push_back({i, j});
        }
    }

    for (pair<int, int>& p : mask) {
        for (int i = 0; i < n; i++) {
            matrix[p.first][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            matrix[i][p.second] = 0;
        }
    }
}