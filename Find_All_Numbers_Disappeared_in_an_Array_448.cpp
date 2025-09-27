//
// Created by Anh Le on 3/18/25.
//
vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<bool> check(nums.size() + 1);

    for (int i = 0; i < nums.size(); i++)
        check[nums[i]] = true;

    vector<int> ans;

    for (int i = 1; i <= nums.size(); i++)
    {
        if (!check[i])
            ans.push_back(i);
    }
    return ans;
}
