//
// Created by Anh Le on 9/4/26.
//
int ans = 0;

pair<int,int> dfs(TreeNode* node, TreeNode* parent)
{
    if (node == nullptr) return {0,0};
    pair<int,int> l = dfs(node->left, node);
    pair<int,int> r = dfs(node->right, node);

    int leftInc = l.first;
    int leftDec = l.second;

    int rightInc = r.first;
    int rightDec = r.second;

    ans = max({ans,leftInc + rightDec + 1, leftDec + rightInc + 1});
    if (parent && node->val == parent->val + 1)
        return {max(leftInc, rightInc) + 1, 0};
    if (parent && node->val == parent->val -1)
        return {0, max(leftDec, rightDec)+1};
    return  {0,0};
}
int longestConsecutive(TreeNode* root) {
    dfs(root, nullptr);
    return ans;
}