//
// Created by Anh Le on 3/12/25.
//
#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int max_ones = -1;
    int i = 0;
    while (i < nums.size())
    {
        int count = 0;
        while (i < nums.size() && nums[i] == 1)
        {
            count++;
            i++;
        }
        i++;
        max_ones = std::max(max_ones, count);
    }
    return max_ones;
}
