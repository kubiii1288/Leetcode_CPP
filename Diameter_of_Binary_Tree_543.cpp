//
// Created by Anh Le on 6/1/26.
//

int ans = 0;

int dfs(TreeNode* node)
{
    if (node == nullptr) return 0;
    int left = dfs(node->left);
    int right = dfs(node->right);

    ans = max(ans, left+right);
    return  1+ max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    dfs(root);
    return ans;
}