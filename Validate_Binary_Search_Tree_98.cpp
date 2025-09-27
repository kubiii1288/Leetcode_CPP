//
// Created by Anh Le on 3/23/25.
//

#include <algorithm>
#include "TreeNode.h"

int maxValue(TreeNode* root);
bool valid(TreeNode* root);

bool isValidBST(TreeNode* root)
{
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right == nullptr) return true;
    if (root->left != nullptr && root->right == nullptr) return root->left->val < root->val && root->val <
        maxValue(root->right) && isValidBST(root->right);
    if (root->right != nullptr && root->left == nullptr) return root->val < root->right->val && maxValue(root->left) <
        root->val && isValidBST(root->left);

    return (root->left->val < root->val && root->val < root->right->val && maxValue(root->left) < root->val && root->val
        < maxValue(root->right) && isValidBST(root->left) && isValidBST(root->right));
}

int maxValue(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr) return root->val;
    if (root->left != nullptr && root->right == nullptr) return std::max(maxValue(root->left), root->val);
    if (root->right != nullptr && root->left == nullptr) return std::max(maxValue(root->right), root->val);

    return std::max(std::max(maxValue(root->left), root->val), maxValue(root->right));
}
