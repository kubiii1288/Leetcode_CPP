//
// Created by Anh Le on 3/18/25.
//
#include<iostream>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums)
{
    vector<int> ans(nums.size());

    int p_even = 0, p_odd = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            ans[p_even++] = nums[i];
        }
        else
        {
            ans[p_odd--] = nums[i];
        }
    }
    return ans;
}
