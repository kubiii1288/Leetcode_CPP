//
// Created by Anh Le on 8/26/25.
//

#include <iostream>
#include <vector>
using namespace std;
#ifndef LEETCODE_MAXIMUM_AREA_OF_LONGEST_DIAGONAL_RECTANGLE_3000_H
#define LEETCODE_MAXIMUM_AREA_OF_LONGEST_DIAGONAL_RECTANGLE_3000_H


class Maximum_Area_of_Longest_Diagonal_Rectangle_3000
{
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
};


#endif //LEETCODE_MAXIMUM_AREA_OF_LONGEST_DIAGONAL_RECTANGLE_3000_H