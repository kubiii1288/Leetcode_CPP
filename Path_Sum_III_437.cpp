//
// Created by Anh Le on 5/31/26.
//
int ans = 0;
void solve(TreeNode* root, long long target, long long current)
{
    if (root == nullptr) return;
    current += root->val;
    if (current == target)
        ans++;
    solve(root->left, target, current);
    solve(root->right, target, current);
}
int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return 0;
    solve(root, targetSum, 0);
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    return ans;
}



int ans = 0;
unordered_map<long long, int> mp;

void dfs(TreeNode* node, long long current, long long target)
{
    if (node == nullptr) return;
    current+= node->val;
    if (mp.count(current - target))
        ans += mp[current - target];
    mp[current]++;
    dfs(node->left, current, target);
    dfs(node->right, current, target);
    mp[current]--;
}
int pathSum(TreeNode* root, int targetSum) {
    mp[0] = 1;
    dfs(root, 0, targetSum);
    return ans;
}

