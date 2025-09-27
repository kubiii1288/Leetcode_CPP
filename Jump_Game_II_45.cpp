//
// Created by Anh Le on 9/15/25.
//

int jump(vector<int>& nums)
{
    int size = nums.size();
    if (size == 1)
        return 0;
    int ans = 0;
    int left = 0;
    int right = 0;
    while (right < size - 1)
    {
        int max_jump = 0;
        for (int i = left; i <= right; i++)
        {
            max_jump = max(max_jump, i + nums[i]);
        }
        left = right + 1;
        right = max_jump;
        ans++;
    }
    return ans;
}
