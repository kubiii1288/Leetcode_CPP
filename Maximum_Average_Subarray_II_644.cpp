//
// Created by Anh Le on 9/19/26.
//

double findMaxAverage(vector<int>& nums, int k) {
    const int N = nums.size();
    vector<double> prefixSum(nums.size(),0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < N; i++)
        prefixSum[i] = nums[i] + prefixSum[i-1];
    double ans = INT_MIN;
    for (int l = 0; l <= N - k; l ++)
    {
        for (int size = k; l + size -1 < N; size++)
        {
            int r = l + size - 1;
            double sum = prefixSum[r] - prefixSum[l] + nums[l];
            double avg = sum / size;
            ans = max(ans, avg);
        }
    }
    return ans;
}



bool isPossible(vector<int> &nums, const int N, double target, int k)
{
    double currentSum = 0;
    for (int i = 0; i < k; i++)
    {
        currentSum += (nums[i] - target);
    }
    if (currentSum >= 0)
        return true;
    double prefixSum = 0;
    double minPrefix = 0;

    for (int i = k; i < N; i++)
    {
        //extend the right side
        currentSum == (nums[i] - target);
        prefixSum += nums[i-k] - target;
        minPrefix = min(minPrefix, prefixSum);
        if (currentSum - minPrefix >= 0)
            return true;
    }
    return false;
}
double findMaxAverage(vector<int>& nums, int k) {
    const int N = nums.size();
    double l = *min_element(nums.begin(), nums.end());
    double r = *max_element(nums.begin(), nums.end());
    double mid;
    while (r- l >= 1e-5)
    {
        mid = (l + r) / 2;
        if (isPossible(nums, N, mid, k))
        {
            l = mid;
        } else r = mid;
    }
    return mid;
}