//
// Created by Anh Le on 6/22/26.
//

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int M = matrix.size();
    const int N = matrix[0].size();
    int r = 0;
    int c = N - 1;
    while (r < M && c >= 0) {
        if (matrix[r][c] > target) {
            c--;
        } else if (matrix[r][c] < target) {
            r++;
        } else
            return true;
    }
    return false;
}