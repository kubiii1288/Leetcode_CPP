//
// Created by Anh Le on 7/21/26.
//
int firstMissingPositive(vector<int>& nums) {
    int N = nums.size();
    unordered_set<int> have;
    for (int i : nums)
        have.insert(i);
    for (int i = 1; i <= N+1; i++)
    {
        if (!have.count(i))
            return i;
    }
    return -1;
}