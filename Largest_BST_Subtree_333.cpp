//
// Created by Anh Le on 9/8/26.
//
int ans = 0;
int count(TreeNode* node)
{
    if (node == nullptr) return 0;
    return 1 + count(node->left) + count(node->right);
}

bool isValid(TreeNode* root, long long leftBound, long long rightBound) {
    if (root == nullptr)
        return true;
    return leftBound < root->val && root->val < rightBound &&
           isValid(root->left, leftBound, root->val) &&
           isValid(root->right, root->val, rightBound);
}
bool isValidBST(TreeNode* root) {
    return isValid(root, LONG_LONG_MIN, LONG_LONG_MAX);
}

void solve(TreeNode* node)
{
    if (node == nullptr) return;
    if (isValidBST(node))
        ans = max(ans,count(node));
    solve(node->left);
    solve(node->right);
}
int largestBSTSubtree(TreeNode* root) {
    solve(root);
    return ans;
}