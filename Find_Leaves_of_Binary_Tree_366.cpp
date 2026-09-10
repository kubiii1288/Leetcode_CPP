//
// Created by Anh Le on 9/7/26.
//
TreeNode* traverse(TreeNode* node, vector<int> &leaves)
{
    if (node == nullptr) return nullptr;
    if (node->left == nullptr && node->right == nullptr)
    {
        leaves.push_back(node->val);
        // delete node;
        return nullptr;
    }
    node->left = traverse(node->left, leaves);
    node->right = traverse(node->right, leaves);
    return node;
}
vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ans;
    while (root != nullptr)
    {
        vector<int> leaves;
        root = traverse(root,leaves);
        ans.push_back(std::move(leaves));
    }
    return std::move(ans);
}