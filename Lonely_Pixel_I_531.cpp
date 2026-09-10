//
// Created by Anh Le on 8/29/26.
//
int findLonelyPixel(vector<vector<char>>& picture) {
    const int M = picture.size();
    const int N = picture[0].size();
    int ans = 0;
    for (int r = 0; r < M; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (picture[r][c] == 'B')
            {
                // check row
                for (int i = c+1; i < N; i++)
                {
                    if (picture[r][i] == 'B')
                        goto skip;
                }
                // check column
                for (int i = r +1; i < M; i++)
                    if (picture[i][c] == 'B')
                        goto skip;
                for (int i = r-1; i >=0; i--)
                    if (picture[i][c] == 'B')
                        goto skip;
                ans++;
            }
        }
        skip:
}
    return ans;
}