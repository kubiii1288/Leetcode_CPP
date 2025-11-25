//
// Created by Anh Le on 10/29/25.
//
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
         vector<string>& ans, int x, int y, int M, int N,
         unordered_set<string>& words, string current, int max_deep) {
    if (current.size() > max_deep)
        return;
    if (words.find(current) != words.end()) {
        ans.push_back(current);
        words.erase(current);
    }

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (0 <= xx && xx < M && 0 <= yy && yy < N && !visited[xx][yy]) {
            dfs(board, visited, ans, xx, yy, M, N, words,
                current + board[xx][yy], max_deep);
        }
    }
    visited[x][y] = false;
}

vector<string> findWords(vector<vector<char>>& board,
                         vector<string>& words) {
    const int M = board.size();
    const int N = board[0].size();
    unordered_set<string> s;
    int max_depth = -1;
    for (int i = 0; i < words.size(); i++) {
        max_depth =
            (words[i].size() > max_depth) ? words[i].size() : max_depth;
        s.insert(words[i]);
    }
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    vector<string> ans;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(board, visited, ans, i, j, M, N, s,
                    string(1, board[i][j]), max_depth);
            }
        }
    }
    return ans;
}