//
// Created by Anh Le on 11/26/25.
//
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0;
    int right = matrix[0].size()-1;
    int top = 0;
    int bot = matrix.size()-1;
    int  mid_horizontal;
    while (top <= bot)
    {
        mid_horizontal = (top + bot) /2;
        if (matrix[mid_horizontal][left] <= target && target <= matrix[mid_horizontal][right])
        {
            break;
        }
        if (target < matrix[mid_horizontal][left])
        {
            bot = mid_horizontal -1;
        } else
        {
            top = mid_horizontal + 1;
        }
    }

    return binary_search(matrix[mid_horizontal].begin(), matrix[mid_horizontal].end(), target);
}