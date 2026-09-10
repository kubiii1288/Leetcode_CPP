//
// Created by Anh Le on 5/7/26.
//
int get_parent(vector<int>& parent, int i)
{
    if (i == parent[i])
        return i;
    return parent[i] = get_parent(parent, parent[i]);
}

void merge(vector<int>& nums, vector<int>& parent, int a, int b)
{
    int p_a = get_parent(parent, a);
    int p_b = get_parent(parent, b);

    if (nums[p_a] > nums[p_b])
    {
        parent[p_b] = p_a;
    }
    else
        parent[p_a] = p_b;
}

vector<int> maxValue(vector<int>& nums)
{
    const int size = nums.size();
    vector<int> parent(size, -1);
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
    }
    vector<int> pre(size);
    vector<int> suf(size);
    pre[0] = nums[0];
    for (int i = 1; i < size; i++)
    {
        pre[i] = max(nums[i], pre[i - 1]);
    }
    suf[size - 1] = nums[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        suf[i] = min(nums[i], suf[i + 1]);
    }
    for (int i = 0; i + 1 < size; i++)
    {
        if (pre[i] > suf[i + 1])
        {
            merge(nums, parent, i, i + 1);
        }
    }

    vector<int> ans(size, -1);
    for (int i = 0; i < size; i++)
    {
        ans[i] = nums[get_parent(parent, i)];
    }
    return ans;
}
