//
// Created by Anh Le on 10/28/25.
//
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x,
         int y, int M, int N, string& word, int index) {
    if (index == word.size() - 1) {
        // cout << "found" << endl;
        return true;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (0 <= xx && xx < M && 0 <= yy && yy < N &&
            visited[xx][yy] == false && board[xx][yy] == word[index + 1]) {
            // cout << "dfs row: " << "-" << xx << " colum-" << yy << ": "
            // << board[xx][yy] << endl;
            if (dfs(board, visited, xx, yy, M, N, word, index + 1))
                return true;
            visited[xx][yy] = false;
            }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    const int M = board.size();
    const int N = board[0].size();
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && board[i][j] == word[0]) {
                // cout << "start searching row: " << "-" << i << " colum-"
                // << j << ": " << board[i][j] << endl;
                if (dfs(board, visited, i, j, M, N, word, 0))
                    return true;
                visited[i][j] = false;
            }
        }
    }
    return false;
}