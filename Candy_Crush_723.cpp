//
// Created by Anh Le on 8/29/26.
//

vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    const int M = board.size();
    const int N = board[0].size();

    bool stable = false;
    while (!stable)
    {
       int crushed = 0;
        for (int i = 0; i < M; i++)
        {
            int l = 0, r = 0;
            for (; r < N; r++)
            {
                if (abs(board[i][r]) != abs(board[i][l]))
                {
                    if (r-l >= 3 && abs(board[i][l]) != 0)
                    {
                        for (int p = l; p < r;p++)
                        {
                            board[i][p] = -abs(board[i][p]);
                            crushed++;
                        }
                    }
                    l = r;
                }
            }
            if (r - l >= 3 && abs(board[i][l]) != 0)
            {
                for (int p = l; p < r;p++)
                {
                    board[i][p] = -abs(board[i][p]);
                    crushed++;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            int u = 0, d = 0;
            for (; d < M; d++)
            {
                if (abs(board[d][i]) != abs(board[u][i]))
                {
                    if (d - u >= 3 && abs(board[u][i]) != 0)
                    {
                        for (int p = u; p < d; p++)
                        {
                            board[p][i] = - abs(board[p][i]);
                            crushed++;
                        }
                    }
                    u = d;
                }
            }
            if (d - u >= 3 && abs(board[u][i]) != 0)
            {
                for (int p = u; p < d; p++)
                {
                    board[p][i] = -abs(board[p][i]);
                    crushed++;
                }
            }
        }
        if (crushed == 0)
        {
            stable = true;
            break;
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] < 0)
                    board[i][j] = 0;
            }
        }
        // gravity
        for (int c = 0; c < N; c++)
        {
            int high = M-1, low = M-1;
            for (; high >= 0; high--)
            {
                if (board[high][c] != 0)
                {
                    swap(board[high][c], board[low][c]);
                    low--;
                }
            }
        }
    }
    return board;
}