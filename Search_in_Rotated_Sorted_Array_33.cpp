//
// Created by Anh Le on 12/18/25.
//
int find_min_element(vector<int>& nums)
{
    int left = 0;
    int right = nums.size()-1;
    int mid;
    while (left < right)
    {
        mid = (left + right) /2;
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        } else right = mid;
    }
    return left;
}

int binary_search(vector<int> &nums, int left, int right, int target)
{
    int mid;

    while (left <= right)
    {
        mid = (left + right) /2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target)
            right = mid -1;
        else left = mid + 1;
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int min_index = find_min_element(nums);
    cout << "min index: " << min_index << endl;
    int ans = binary_search(nums, 0, min_index-1, target);
    if (ans == -1)
        return binary_search(nums, min_index, nums.size()-1, target);
    retur