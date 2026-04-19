vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    if (root == nullptr) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    bool rev = false;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode* front = q.front();
            level.push_back(front->val);
            q.pop();
            if (front->left != nullptr) q.push(front->left);
            if (front->right != nullptr) q.push(front->right);
        }
        if (rev)
        {
            reverse(level.begin(), level.end());
        }
        rev = !rev;
        ans.emplace_back(move(level));
    }
    return ans;
}
