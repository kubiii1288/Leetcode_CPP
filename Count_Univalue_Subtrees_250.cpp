//
// Created by Anh Le on 9/7/26.
//
int ans = 0;
bool isUniValue(TreeNode* node)
{
    if (node == nullptr) return true;
    bool l = isUniValue(node->left);
    bool r = isUniValue(node->right);

    if (!l || !r) return false;
    if (node->left && node->left->val != node->val)
        return false;
    if (node->right && node->right->val != node->val)
        return false;
    ans++;
    return true;
}
int countUnivalSubtrees(TreeNode* root) {
    isUniValue(root);
    return ans;
}