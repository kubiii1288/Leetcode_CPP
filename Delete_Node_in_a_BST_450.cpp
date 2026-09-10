//
// Created by Anh Le on 8/11/26.
//

TreeNode* deleteNode(TreeNode* root, int key) {

    if (root == nullptr)
        return root;
    if (root->val > key)
    {
        root->left = deleteNode(root->left,key);
    } else if (root->val < key)
    {
        root->right = deleteNode(root->right,key);
    } else
    {
        if (root->left == nullptr)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* succ = root->right;
        while (succ && succ->left)
            succ = succ->left;
        root->val = succ->val;
        root->right = deleteNode(root->right,succ->val);
    }
    return root;
}