//
// Created by Anh Le on 5/1/26.
//
int solve_recursive(TreeNode* root, unordered_map<TreeNode*, int> &memo)
{
    if (root == nullptr) return 0;
    if (memo.find(root) != memo.end()) return memo[root];
    int include_root = root->val;
    if (root->left != nullptr)
    {
        include_root += solve_recursive(root->left->left, memo);
        include_root += solve_recursive(root->left->right,memo);
    }
    if (root->right != nullptr)
    {
        include_root += solve_recursive(root->right->right, memo);
        include_root += solve_recursive(root->right->left, memo);
    }
    int not_include_root = solve_recursive(root->left, memo) + solve_recursive(root->right, memo);
    return memo[root] = max(include_root,not_include_root);
}
int rob(TreeNode* root) {
    unordered_map<TreeNode*, int> memo;
    return solve_recursive(root, memo);
}

// return pair of maximum value can get at TreeNode* root when we rob or skip
pair<int,int> dfs(TreeNode* root)
{
    // first = robbed
    // second = skipped
    if (root == nullptr) return std::move<pair<int,int>>({0,0});
    pair<int,int> left  = dfs(root->left);
    pair<int,int> right  = dfs(root->right);

    int rob = root->val + left.second + right.second;
    int skip = max(left.first, left.second) + max(right.first, right.second);
    pair<int,int> p = {rob,skip};
    return std::move(p);
}
int rob_dfs(TreeNode* root) {
    pair<int,int> p = dfs(root);
    return max(p.first, p.second);
}