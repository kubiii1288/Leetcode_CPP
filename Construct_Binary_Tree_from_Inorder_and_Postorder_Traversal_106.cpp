unordered_map<int,int> mp;
TreeNode* build(vector<int> &in, int leftI, int rightI, vector<int> &pos, int leftP, int rightP)
{
    if (leftI > rightI || leftP > rightP) return nullptr;
    TreeNode* root = new TreeNode(pos[rightP]);
    int mid = mp[pos[rightP]];
    int leftSize = mid - leftI;
    root->left = build(in, leftI, mid-1, pos, leftP, leftP + leftSize -1);
    root->right = build (in, mid +1, rightI, pos, leftP + leftSize, rightP-1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) return nullptr;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}