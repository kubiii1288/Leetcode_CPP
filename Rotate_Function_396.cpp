//
// Created by Anh Le on 4/30/26.
//
int maxRotateFunction(vector<int>& nums) {
    const int size = nums.size();
    int sum = 0;
    int F = 0;
    for (int i = 0; i < size; i++) {
        F += nums[i] * i;
        sum += nums[i];
    }
    int ans = F;
    for (int i = 1; i < size; i++) {
        F = F + sum - size * nums[size - i];
        ans = max(ans, F);
    }
    return ans;
}