//
// Created by Anh Le on 10/23/25.
//

bool is_valid(vector<int>& board, int row)
{
    for (int i = 0; i < row; i++)
    {
        if (board[row] == board[i])
            return false;
        if (std::abs(board[row] - board[i]) == row - i)
            return false;
    }
    return true;
}

void solve(vector<int>& board, int N, int row, vector<vector<string>>& ans)
{
    if (row == N)
    {
        vector<string> sol;
        for (int i = 0; i < N; i++)
        {
            string r(N, '.');
            r[board[i]] = 'Q';
            sol.push_back(r);
        }
        ans.push_back(sol);
        return;
    }
    for (int j = 0; j < N; j++)
    {
        board[row] = j;
        if (is_valid(board, row))
        {
            solve(board, N, row + 1, ans);
        }
        board[row] = -1;
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<int> board(n, -1);
    solve(board, n, 0, ans);
    return ans;
}
