//
// Created by Anh Le on 9/12/25.
//
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    for (vector<int>::iterator first = nums.begin(); first != nums.end();)
    {
        int duplicate = 0;
        vector<int>::iterator second = first + 1;
        while (second != nums.end() && *second == *first)
        {
            ++second;
            duplicate++;
        }

        if (duplicate > 1)
        {
            nums.erase(first, (first + duplicate) - 1);
        }
        first = second;
    }
    return nums.size();
}
