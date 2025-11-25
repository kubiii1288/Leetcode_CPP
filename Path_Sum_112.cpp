//
// Created by Anh Le on 11/1/25.
//
bool hasPathSum(TreeNode* root, int targetSum)
{
    if (root == nullptr)
        return false;
    if (root->val == targetSum && root->left == nullptr && root->right == nullptr)
        return true;
    return hasPathSum(root->left, targetSum - root->val) ||
        hasPathSum(root->right, targetSum - root->val);
}
