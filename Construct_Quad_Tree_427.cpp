//
// Created by Anh Le on 11/14/25.
//
int compute(int row, int column, int N, vector<vector<int>>& grid) {
    int sum = 0;
    for (int i = row; i < row + N; i++) {
        for (int j = column; j < column + N; j++) {
            sum += grid[i][j];
        }
    }
    return sum;
}
Node* construct_node(int row, int column, int N,
                     vector<vector<int>>& grid) {
    int sum = compute(row, column, N, grid);
    if (sum == 0 || sum == (N * N)) {
        return new Node(sum, true, nullptr, nullptr, nullptr, nullptr);
    }

    Node* top_left = construct_node(row, column, N / 2, grid);
    Node* top_right = construct_node(row, column + N / 2, N / 2, grid);
    Node* bot_left = construct_node(row + N / 2, column, N / 2, grid);
    Node* bot_right =
        construct_node(row + N / 2, column + N / 2, N / 2, grid);
    return new Node(1, false, top_left, top_right, bot_left, bot_right);
}

Node* construct(vector<vector<int>>& grid) {
    if (grid.empty())
        return nullptr;
    const int N = grid.size();

    return construct_node(0, 0, N, grid);
}