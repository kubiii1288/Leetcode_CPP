//
// Created by Anh Le on 5/6/26.
//
vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    const int M = boxGrid.size();
    const int N = boxGrid[0].size();
    vector<vector<char>> ans(N, vector<char>(M, 'x'));
    for (int i = 0; i < M; i++) {
        int empty = N - 1;
        for (int j = N - 1; j >= 0; j--) {
            if (boxGrid[i][j] == '#') {
                swap(boxGrid[i][j], boxGrid[i][empty]);
                empty--;
            } else if (boxGrid[i][j] == '*') {
                empty = j - 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            ans[j][M - i - 1] = boxGrid[i][j];
        }
    }
    return std::move(ans);
}