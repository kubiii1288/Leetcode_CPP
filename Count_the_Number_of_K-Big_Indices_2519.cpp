//
// Created by kubiii on 10/22/26.
//
int kBigIndices(vector<int>& nums, int k) {
    const int n = nums.size();
    priority_queue<int> left, right;
    vector<bool> validLeft(n,false);
    vector<bool> validRight(n,false);

    for (int i = 0; i < n; i++) {
        if (left.size() == k && left.top() < nums[i]) {
            validLeft[i] = true;
        }
        left.push(nums[i]);
        if (left.size() > k)
            left.pop();
    }
    for (int i = n-1; i >=0; i--) {
        if (right.size() == k && right.top() < nums[i]) {
            validRight[i] = true;
        }
        right.push(nums[i]);
        if (right.size() >k)
            right.pop();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (validLeft[i] && validRight[i])
            ans++;
    }
    return ans;
}