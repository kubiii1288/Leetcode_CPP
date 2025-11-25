//
// Created by Anh Le on 11/12/25.
//

void search(TreeNode* root, const int target, int &ans, int &order)
{
    if (root == nullptr || ans != -1) return;
    search(root->left, target, ans, order);
    order++;
    if (order == target)
    {
        ans = root->val;
        return;
    }
    search(root->right, target,ans,order);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    int order = 0;
    search(root, k, ans,order);
    return ans;
}