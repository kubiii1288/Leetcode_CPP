pair<int, int> getPos(const int size, int pos) {
    int r = (pos - 1) / size;
    int c = (pos - 1) % size;
    if (r % 2)
        c = size - c - 1;
    return std::move<pair<int, int>>({r, c});
}
int snakesAndLadders(vector<vector<int>>& board) {
    const int n = board.size();
    reverse(board.begin(), board.end());
    vector<bool> visited(n * n + 1, false);
    queue<pair<int, int>> q;

    q.push({1, 0});
    visited[1] = 0;
    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();
        if (curr == n * n)
            return steps;
        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next > n * n)
                break;
            auto [r, c] = getPos(n, next);
            if (board[r][c] != -1)
                next = board[r][c];

            if (!visited[next]) {
                visited[next] = true;
                q.push({next, steps + 1});
            }
        }
    }
    return -1;
}