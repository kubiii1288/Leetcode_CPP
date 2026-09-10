//
// Created by Anh Le on 9/4/26.
//
int ans = 0;
void dfs(TreeNode* node, int prev, int currentLen) {
    if (node == nullptr)
        return;
    if (node->val == prev + 1) {
        currentLen++;
    } else
        currentLen = 1;
    ans = max(ans,currentLen);
    dfs(node->left, node->val, currentLen);
    dfs(node->right, node->val, currentLen);
}
int longestConsecutive(TreeNode* root) {
    dfs(root, -1e9, 0);
    return ans;
}