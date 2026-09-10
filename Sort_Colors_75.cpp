//
// Created by Anh Le on 7/24/26.
//
void sortColors(vector<int>& nums) {
    int count[3] = {0};
    for (int i : nums)
        count[i]++;
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        while (count[i]-- > 0)
            nums[index++] = i;
    }
}