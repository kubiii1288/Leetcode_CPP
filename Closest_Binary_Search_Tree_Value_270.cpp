//
// Created by Anh Le on 9/8/26.
//
int closestValue(TreeNode* root, double target) {
    TreeNode* node = root;
    int ans = node->val;
    while (node)
    {
        double currentGap = abs(node->val - target);
        double bestGap = abs(ans - target);
        if (currentGap < bestGap || (currentGap == bestGap && node->val < ans))
        {
            ans = node->val;
        }
        if (target < node->val)
            node = node->left;
        else node = node->right;
    }
    return ans;
}