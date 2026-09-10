//
// Created by Anh Le on 9/7/26.
//
double ans = numeric_limits<double>::min();

pair<double,int> traverse(TreeNode* node)
{
    if (node == nullptr) return {0,0};
    double sum = node->val;
    pair<double,int> left = traverse(node->left);
    pair<double,int> right = traverse(node->right);
    sum += (left.first * left.second + right.first * right.second);
    int cnt = (1 + left.second + right.second);
    double average = (sum) / (cnt);
    ans = max(average,ans);
    return {average,cnt};
}
double maximumAverageSubtree(TreeNode* root) {
    traverse(root);
    return ans;
}