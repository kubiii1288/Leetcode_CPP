//
// Created by Anh Le on 9/21/26.
//
class TicTacToe {
public:
    vector<vector<int>> r, c;
    int d[2][2] = {0};
    int size;
    TicTacToe(int n) {
        size = n;
        r.resize(2, vector<int>(n, 0));
        c.resize(2, vector<int>(n, 0));
    }

    int move(int row, int col, int player) {
        player--;
        r[player][row]++;
        c[player][col]++;
        if (row == col) {
            d[player][0]++;
        }
        if (row + col == size - 1) {
            d[player][1]++;
        }
        if (r[player][row] == size || c[player][col] == size ||
            d[player][0] == size || d[player][1] == size)
            return player + 1;
        return 0;
    }
};