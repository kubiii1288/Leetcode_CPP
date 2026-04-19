//
// Created by Anh Le on 12/15/25.
//
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        double sum = 0;
        int current_size = q.size();

        for (int i = 0; i < current_size; i++) {
            sum += q.front()->val;
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        ans.push_back(sum / current_size);
    }
    return ans;
}