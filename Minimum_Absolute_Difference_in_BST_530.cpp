//
// Created by Anh Le on 12/3/25.
//
TreeNode* previous_node = nullptr;
int ans = 1e6;
void search(TreeNode* root) {
    if (root == nullptr)
        return;
    search(root->left);
    if (previous_node != nullptr) {
        ans = std::min(ans, root->val - previous_node->val);
    }
    previous_node = root;
    search(root->right);
}

int getMinimumDifference(TreeNode* root) {
    search(root);
    return ans;
}