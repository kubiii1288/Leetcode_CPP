//
// Created by Anh Le on 8/26/25.
//
#include <iostream>
#include <vector>
using namespace std;
int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    double max_diagonal = -1;
    double max_area = -1;

    for (vector<int>& rec : dimensions)
    {
        double diagonal = rec[0] * rec[0] + rec[1] * rec[1];
        double area = rec[0] * rec[1];

        if (diagonal > max_diagonal)
        {
            max_diagonal = diagonal;
            max_area = area;
        } else if (diagonal == max_diagonal && area > max_area)
        {
            max_area = area;
        }
    }
    return max_area;
}