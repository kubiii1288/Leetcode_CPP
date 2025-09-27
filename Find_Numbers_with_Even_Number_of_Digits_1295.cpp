//
// Created by Anh Le on 3/12/25.
//
#include<iostream>
using namespace std;

int findNumbers(vector<int>& nums)
{
    int max_even_digits = 0;
    for (const int num : nums)
    {
        int digits = int(log10(num)) + 1;
        if (digits % 2 == 0)
        {
            max_even_digits++;
        }
    }
    return max_even_digits;
}
