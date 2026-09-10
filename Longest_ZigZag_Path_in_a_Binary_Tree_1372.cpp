//
// Created by Anh Le on 8/10/26.
//
int ans = 0;
void dfs(TreeNode* node, int left, int right) {
    if (node == nullptr)
        return;
    ans = max({ans, left, right});

    dfs(node->left, right + 1, 0);
    dfs(node->right, 0, left + 1);
}
int longestZigZag(TreeNode* root) {
    dfs(root, 0, 0);
    return ans;
}