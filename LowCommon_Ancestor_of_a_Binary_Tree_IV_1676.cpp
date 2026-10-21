//
// Created by kubiii on 10/21/26.
//

TreeNode* dfs(TreeNode* root, unordered_set<TreeNode*> &target) {
    if (root == nullptr) return nullptr;
    if (target.count(root))
        return root;
    TreeNode* l = dfs(root->left, target);
    TreeNode* r = dfs(root->right, target);
    if (l && r) return root;
    return l ? l : r;
}
TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    unordered_set<TreeNode*> target(nodes.begin(), nodes.end());
    return dfs(root, target);
}