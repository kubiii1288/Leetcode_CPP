//
// Created by Anh Le on 1/26/26.
//
int minimumTotal(vector<vector<int>>& triangle)
{
    for (int i = 1; i <triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                triangle[i][j] += triangle[i-1][0];
            } else if (j == triangle[i].size()-1)
            {
                triangle[i][j] += triangle[i-1].back();
            }
            else
            {
                triangle[i][j] = min(triangle[i-1][j],triangle[i-1][j-1]) + triangle[i][j];
            }
        }
    }
    int ans = INT_MAX;
    for (int i : triangle.back())
    {
        ans = min(ans,i);
    }
    return ans;
}