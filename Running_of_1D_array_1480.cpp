//
// Created by Anh Le on 3/11/25.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> rs(nums.size());
    rs[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
       rs[i] = rs[i-1] + nums[i];
    }
    return rs;
}
