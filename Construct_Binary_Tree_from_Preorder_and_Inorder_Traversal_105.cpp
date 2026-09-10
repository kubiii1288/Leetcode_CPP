unordered_map<int, int> mp;
TreeNode* build(vector<int>& preOrder, int lefP, int rightP,
                vector<int>& inorder, int leftI, int rightI) {
    if (lefP > rightP || leftI > rightI)
        return nullptr;
    TreeNode* root = new TreeNode(preOrder[lefP]);
    int mid = mp[preOrder[lefP]];
    int leftSize = mid - leftI;
    root->left =
        build(preOrder, lefP + 1, lefP + leftSize, inorder, leftI, mid - 1);
    root->right = build(preOrder, lefP + leftSize + 1, rightP, inorder,
                        mid + 1, rightI);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty())
        return nullptr;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return build(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1);
}