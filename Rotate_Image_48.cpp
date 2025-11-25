//
// Created by Anh Le on 10/5/25.
//
void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < N; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}