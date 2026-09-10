//
// Created by Anh Le on 9/7/26.
//

vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) return {};
    map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int index = q.front().second;
        q.pop();
        mp[index].push_back(node->val);
        if (node->left)
            q.push({node->left, index - 1});
        if (node->right)
            q.push({node->right, index + 1});
    }
    vector<vector<int>> ans;
    for (map<int, vector<int>>::iterator it = mp.begin(); it != mp.end();
         ++it)
        ans.push_back(it->second);
    return ans;
}