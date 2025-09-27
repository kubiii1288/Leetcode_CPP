//
// Created by Anh Le on 3/13/25.
//

#include <iostream>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
}
