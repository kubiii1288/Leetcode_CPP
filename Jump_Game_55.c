//
// Created by Anh Le on 9/15/25.
//

#include<iostream>

using namespace std;

bool canJump(vector<int>& nums) {
	int size = nums.size();
	int max_jump = 0;
	for (int i = 0; i < size -1; i++) {
		if (i > max_jump)
			return false;
		max_jump = max(max_jump, i + nums[i]);
	}
	return max_jump >= size - 1;
}
