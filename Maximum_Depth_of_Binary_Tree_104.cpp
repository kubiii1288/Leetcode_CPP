//
// Created by Anh Le on 10/6/25.
//

int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}