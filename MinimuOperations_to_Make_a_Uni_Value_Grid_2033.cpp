//
// Created by Anh Le on 4/27/26.
//
int minOperations(vector<vector<int>>& grid, int x) {
    int size = grid.size() * grid[0].size();
    int r = grid[0][0] % x;
    vector<int> op;
    op.reserve(size);
    for (vector<int> &v : grid)
    {
        for (int &i : v)
        {
            op.push_back((abs(i-r)/x));
            if (i % x != r) return -1;
        }
    }

    nth_element(op.begin(),op.begin()+size/2 , op.end());
    int median = op[size/2];
    int ans= 0;
    for (int &i : op)
    {
        ans+= abs(i-median);
    }
    return ans;
}
