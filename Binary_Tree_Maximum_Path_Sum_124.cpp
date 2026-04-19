//
// Created by Anh Le on 4/4/26.
//
int solve(TreeNode *root, int &global_max)
{
    if (root == nullptr) return 0;
    int maxLeft = max(0, solve(root->left, global_max));
    int maxRight = max(0, solve(root->right, global_max));
    global_max = max(global_max, maxLeft + root->val + maxRight);
    return root->val + max(maxLeft, maxRight);
}
int maxPathSum(TreeNode* root) {
    int best_path_sum = INT_MIN;
    solve(root, best_path_sum);
    return best_path_sum;
}