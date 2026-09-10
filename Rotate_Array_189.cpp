//
// Created by Anh Le on 9/13/25.
//
#include <iostream>

using namespace std;

void rotate(vector<int>& nums, int k)
{
    const int size = nums.size();
    if (k >= size) k = k % size;
    if (k == 0) return;
    int temp[k];
    for (int i = 0; i < k; i++)
        temp[i] = nums[size - k + i];

    for (int i = size - 1; i >= k; i--)
        nums[i] = nums[i - k];

    for (int i = 0; i < k; i++)
        nums[i] = temp[i];
}

void rotate_2(vector<int>& nums, int k) {
    k %= nums.size();
    if (k == 0 || nums.size() == 1) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
