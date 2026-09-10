//
// Created by Anh Le on 9/7/26.
//


void getLeaves(TreeNode* root, vector<int> &nodes)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
        nodes.push_back(root->val);
    getLeaves(root->left, nodes);
    getLeaves(root->right, nodes);
}


vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> ans;
    ans.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr)
        return ans;

    // collect left boundary
    TreeNode* current = root->left;
    while (current)
    {
        if (current->left != nullptr || current->right != nullptr)
            ans.push_back(current->val);
        if (current->left !=nullptr)
            current = current->left;
        else current = current->right;
    }
    // collect leaves
    getLeaves(root, ans);

    // collect right
    current = root->right;
    vector<int> right;
    while (current)
    {
        if (current->left !=nullptr || current->right != nullptr)
            right.push_back(current->val);
        if (current->right != nullptr)
            current = current->right;
        else current = current->left;
    }
    for (vector<int>::reverse_iterator it = right.rbegin(); it != right.rend(); ++it)
        ans.push_back(*it);
    return ans;
}