//
// Created by Anh Le on 9/7/26.
//

vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<vector<double>>pq;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();
        pq.push({-abs(current->val - target), static_cast<double>(current->val)});
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
    vector<int> ans;
    while (k-->0)
    {
        ans.push_back(pq.top()[1]);
        pq.pop();
    }
    return ans;
}