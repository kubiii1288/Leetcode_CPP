//
// Created by Anh Le on 9/1/26.
//
vector<int> findPermutation(string s)
{
    const int n = s.size()+1;
    vector<int> ans;
    ans.reserve(n);
    stack<int> stk;
    for (int i = 0; i < n;i++)
    {
        stk.push(i+1);
        if (i == n-1 || s[i] == 'I')
        {
            while (!stk.empty())
            {
                ans.push_back(stk.top());
                stk.pop();
            }
        }
    }
    return ans;
}