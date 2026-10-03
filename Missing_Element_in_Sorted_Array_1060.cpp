//
// Created by Anh Le on 9/17/26.
//
int missingElement(vector<int>& nums, int k)
{
    int N = nums.size();
    int totalMissing = nums.back() - nums.front() - (N - 1);
    if (k > totalMissing)
        return nums.back() + (k - totalMissing);
    int l = 0, r = N - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int missing = nums[mid] - nums.front() - mid;
        if (missing >= k)
            r = mid;
        else l = mid + 1;
    }
    l--;
    int missing = nums[l] - nums.front() - l;
    return nums[l] + (k - missing);
}