TreeNode* createNode(vector<int>& arr, int left, int right)
{
    if (left > right) return nullptr;
    int mid = (left + right) / 2;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = createNode(arr, left, mid - 1);
    node->right = createNode(arr, mid + 1, right);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return createNode(nums, 0, nums.size() - 1);
}
