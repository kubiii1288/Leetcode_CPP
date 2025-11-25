//
// Created by Anh Le on 11/14/25.
//
bool dfs(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr ^ right == nullptr)
        return false;
    return left->val == right->val && dfs(left->right, right->left) &&
           dfs(left->left, right->right);
}
bool isSymmetric(TreeNode* root) {
    if (root == nullptr)
        return true;
    return dfs(root->left, root->right);
}