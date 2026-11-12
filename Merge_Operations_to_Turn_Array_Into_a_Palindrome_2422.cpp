//
// Created by kubiii on 10/21/26.
//

int minimumOperations(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    long long left = nums[l];
    long long right = nums[r];
    int ans = 0;
    while (l < r) {
        if (left == right) {
            l++;
            r--;
            left =nums[l];
            right = nums[r];
        } else if (left < right) {
            left += nums[l+1];
            l++;
            ans++;
        } else {
            right += nums[r-1];
            r--;
            ans++;
        }
    }
    return ans;
}
