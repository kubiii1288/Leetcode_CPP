bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> row[9], column[9], square[9];
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.')
                continue;
            char current = board[r][c];
            if (row[r].find(current) == row[r].end()) {
                row[r].insert(current);
            } else
                return false;
            if (column[c].find(current) == column[c].end()) {
                column[c].insert(current);
            } else
                return false;
        }
    }

    int s = 0;
    for (int r = 0; r < 9; r += 3) {
        for (int c = 0; c < 9; c += 3) {
            for (int i = r; i < r + 3; i++) {
                for (int j = c; j < c + 3; j++) {
                    if (board[i][j] == '.')
                        continue;
                    char current = board[i][j];
                    if (square[s].find(current) == square[s].end()) {
                        square[s].insert(current);
                    } else
                        return false;
                }
            }
            s++;
        }
    }
    return true;
}