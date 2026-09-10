//
// Created by Anh Le on 8/8/26.
//

int longestOnes(vector<int>& nums, int k) {

    int ans = 0;
    int cnt_ones = 0;
    int cnt_zeros = 0;
    for (int left = 0, right = 0; right < nums.size(); right++)
    {
        if (nums[right])
        {
            cnt_ones++;
        } else
        {
            cnt_zeros++;
            while (cnt_zeros > k)
            {
                if (nums[left])
                    cnt_ones--;
                else
                    cnt_zeros--;

                left++;
            }
        }
        ans = max(ans, cnt_ones + cnt_zeros);
    }
    return ans;
}