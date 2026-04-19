vector<vector<int>> levelOrder(TreeNode* root)
{
    if (root == nullptr) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* front = q.front();
            level.push_back(front->val);
            if (front->left != nullptr) q.push(front->left);
            if (front->right != nullptr) q.push(front->right);
            q.pop();
        }
        ans.emplace_back(move(level));
    }
    return ans;
}
