    //
// Created by Anh Le on 9/9/26.
//
bool verifyPreorder(vector<int>& preorder) {
    stack<int> stk;
    int limit = INT_MIN;
    for (int i : preorder)
    {
        if (i <= limit) return false;
        while (!stk.empty() && stk.top() < i)
        {
            limit = stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    return true;
}