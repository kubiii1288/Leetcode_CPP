//
// Created by Anh Le on 4/16/26.
//

void traversal(TreeNode* root, TreeNode*& current)
{
    if (root == nullptr) return;
    current->right = root;
    current = current->right;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    current->left = nullptr;
    traversal(left, current);
    traversal(right, current);
}
void flatten(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode dummy = TreeNode(-1);
    TreeNode* current = &dummy;
    traversal(root,current);
}