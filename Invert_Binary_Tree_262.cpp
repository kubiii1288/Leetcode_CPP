//
// Created by Anh Le on 11/1/25.
//
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)
        return root;
    TreeNode* temp =root->left ;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);;
    return root;
}