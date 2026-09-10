//
// Created by Anh Le on 8/11/26.
//

int maxLevelSum(TreeNode* root) {
    int level = 0;
    int max = INT_MIN;
    int ans = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        level++;
        int size = q.size();
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode* front = q.front();
            q.pop();
            sum += front->val;
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        if (sum > max)
        {
            max = sum;
            ans = level;
        }
    }
    return ans;
}

