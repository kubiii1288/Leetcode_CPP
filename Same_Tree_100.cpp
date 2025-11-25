//
// Created by Anh Le on 10/8/25.
//
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr ^ q == nullptr) return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}