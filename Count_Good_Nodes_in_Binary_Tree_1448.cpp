//
// Created by Anh Le on 8/10/26.
//
static int ans = 0;
void dfs(TreeNode* root, int maxVal)
{
    if (root == nullptr) return;
    if (root->val >= maxVal)
    {
        ans++;
        maxVal = root->val;
    }
    dfs(root->left, maxVal);
    dfs(root->right, maxVal);
}
int goodNodes(TreeNode* root) {
    dfs(root, INT_MIN);
    return ans;
}