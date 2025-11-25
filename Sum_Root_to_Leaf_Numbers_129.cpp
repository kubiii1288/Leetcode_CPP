//
// Created by Anh Le on 11/13/25.
//
void dfs(TreeNode* root, int previous, int& sum)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        sum += (previous * 10 + root->val);
    }
    dfs(root->left, previous * 10 + root->val, sum);
    dfs(root->right, previous * 10 + root->val, sum);
}

int sumNumbers(TreeNode* root)
{
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
}
