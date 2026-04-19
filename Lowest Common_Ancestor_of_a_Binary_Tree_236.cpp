TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q)
        return root;
    TreeNode* findLeft = lowestCommonAncestor(root->left, p, q);
    TreeNode* findRight = lowestCommonAncestor(root->right, p, q);
    if (findLeft != nullptr && findRight != nullptr)
        return root;
    return findLeft == nullptr ? findRight : findLeft;
}