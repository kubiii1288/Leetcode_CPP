//
// Created by Anh Le on 8/10/26.
//
void search(TreeNode* root, vector<int> &arr)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
        arr.push_back(root->val);
    search(root->left,arr);
    search(root->right,arr);
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> arr1, arr2;
    search(root1,arr1);
    search(root2,arr2);
    return arr1 == arr2;
}