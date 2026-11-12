//
// Created by kubiii on 10/23/26.
//
long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
    unordered_map<int,vector<int>> mp;
    vector<bool> existed(1001,false);
    for (int n : nums)
        existed[n] =1;
    for (int i = 0; i <= 1000; i++) {
        if (existed[i])
            mp[i%k].push_back(i);
    }
    long long ans = 1;
    for (auto &[offset,elements] : mp) {
        long long prev1 = 2;
        long long prev2 = 1;
        for (int i = 1; i < elements.size(); i++) {
            long long current;
            if (elements[i] - elements[i-1] == k) {
                current = prev1 + prev2;
            } else {
                current = prev1 * 2;
            }
            prev2 = prev1;
            prev1 = current;
        }
        ans *= prev1;
    }
    return ans;
}