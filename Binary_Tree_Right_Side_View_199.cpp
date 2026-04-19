vector<int> rightSideView(TreeNode* root)
{
    if (root == nullptr) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        const int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* front = q.front();
            if (i == size - 1)
                ans.push_back(front->val);
            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
            q.pop();
        }
    }
    return ans;
}
