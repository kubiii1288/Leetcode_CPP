//
// Created by Anh Le on 8/26/26.
//

int findMaxConsecutiveOnes(vector<int>& nums) {
    int l = 0, r= 0;
    int cnt = 0;
    int ans = 1;
    for (; r < nums.size(); r++)
    {
        if (nums[r] == 0)
            cnt++;
        while (cnt > 1)
        {
            if (nums[l++] == 0)
                cnt--;
        }
        ans = max(ans, r- l +1);
    }
    return ans;
}