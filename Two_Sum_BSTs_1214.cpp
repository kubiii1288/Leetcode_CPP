//
// Created by Anh Le on 9/8/26.
//

bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    unordered_set<int> s;
    queue<TreeNode*> q;
    q.push(root1);
    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();
        s.insert(current->val);
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
    q.push(root2);
    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();
        if (s.count(target - current->val))
            return true;
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
    return false;
}