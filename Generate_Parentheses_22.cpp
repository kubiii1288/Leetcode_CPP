//
// Created by Anh Le on 10/28/25.
//
void generate(vector<string> &ans, string &current, int open, int close, int n)
{
    if (open + close == 2 * n)
    {
        // cout << current << endl;
        ans.push_back(current);
        return;
    }
    if (open < n)
    {
        current.push_back('(');
        generate(ans, current, open + 1, close, n);
        current.pop_back();
    }
    if (close < open)
    {
        current.push_back(')');
        generate(ans,current,open, close + 1,n);
        current.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string current;
    generate(ans, current, 0, 0,n);
    return ans;
}