class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
    }

    int next() {
        TreeNode* top = s.top();
        s.pop();
        TreeNode* current = top->right;
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        return top->val;
    }

    bool hasNext() { return !s.empty(); }
};
