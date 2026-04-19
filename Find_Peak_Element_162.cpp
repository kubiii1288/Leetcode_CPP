//
// Created by Anh Le on 12/16/25.
//
int findPeakElement(vector<int>& nums)
{
    int left, right, mid;
    left = 0;
    right = nums.size()-1;
    while (left <= right)
    {
        if (right - left < 2)
            return (nums[right] > nums[left] ? right : left);
        mid = (left + right) /2;
        if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
            return mid;
        else if (nums[mid-1] > nums[mid])
            right = mid-1;
        else left = mid +1;
    }
    return right;
}