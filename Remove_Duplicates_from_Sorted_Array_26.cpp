//
// Created by Anh Le on 3/15/25.
//
#include<iostream>
#include <unordered_set>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
}