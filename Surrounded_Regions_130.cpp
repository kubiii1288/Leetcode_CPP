void solve(vector<vector<char>>& board)
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    const int M = board.size();
    const int N = board.back().size();

    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++)
    {
        for (int j : {0, N-1})
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'S';
                q.push({i,j});
            }
        }
    }

    for (int j = 0; j < N; j++)
    {
        for (int i : {0, M-1})
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'S';
                q.push({i,j});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (0 <= xx && xx < M && 0 <= yy && yy < N && board[xx][yy] == 'O')
            {
                board[xx][yy] = 'S';
                q.push({xx, yy});
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 'S')
                board[i][j] = 'O';
            else board[i][j] = 'X';
            // cout << board[i][j] << ' ';
        }
        // cout << endl;
    }
}