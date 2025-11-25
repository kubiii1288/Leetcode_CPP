//
// Created by Anh Le on 10/6/25.
//
void gameOfLife(vector<vector<int>>& board) {
    vector<pair<int, int>> dead;
    vector<pair<int, int>> alive;
    const int M = board.size();
    const int N = board[0].size();
    int d_x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int d_y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            int live_neighbors = 0;
            int x, y;
            for (int i = 0; i < 8; i++) {
                x = n + d_x[i];
                y = m + d_y[i];
                if (0 <= x && x < N && 0 <= y && y < M && board[y][x])
                    live_neighbors++;
            }
            bool alive_next = false;
            if (board[m][n]) {
                if (2 <= live_neighbors && live_neighbors <= 3)
                    alive_next = true;
            } else {
                if (live_neighbors == 3)
                    alive_next = true;
            }

            if (alive_next)
                alive.push_back({m, n});
            else
                dead.push_back({m, n});
        }
    }

    for (int i = 0; i < dead.size(); i++) {
        board[dead[i].first][dead[i].second] = 0;
    }

    for (int i = 0; i < alive.size(); i++) {
        board[alive[i].first][alive[i].second] = 1;
    }
}