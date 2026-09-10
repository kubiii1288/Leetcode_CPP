//
// Created by Anh Le on 8/8/26.
//
double findMaxAverage(vector<int>& nums, int k) {
    double ans = std::numeric_limits<double>::lowest();
    double sum = 0;
    for (int left = 0, right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        if (right >= k -1)
        {
            ans = max(ans, sum / k);
            sum -= nums[left];
            left++;
        }
    }
    return ans;
}