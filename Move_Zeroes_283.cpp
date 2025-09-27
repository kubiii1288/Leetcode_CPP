//
// Created by Anh Le on 3/17/25.
//
#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    const int size = nums.size();
    int i = 0, non_zeros_p = 0, cnt = 0;
    while (i < size)
    {
        if (nums[i] != 0)
        {
            nums[non_zeros_p++] = nums[i];
        }
        else cnt++;
        i++;
    }
    for (int i = 0; i < cnt; i++)
    {
        nums[non_zeros_p + i] = 0;
    }
}
