//
// Created by Anh Le on 9/1/26.
//

int helper(const string &s, int& i)
{
    stack<int> stk;
    int num = 0;
    char op = '+';

    for (; i < s.size(); i++)
    {
        char token = s[i];
        if (isdigit(token))
        {
            num = num * 10 + token - '0';
        }

        if (token == '(')
        {
            i++;
            num = helper(s,i);
        }
        if (!isdigit(token) && token != ' ' && token != '(' || i == s.size() -1)
        {
            if (op == '+')
            {
                stk.push(num);
            } else if (op == '-')
            {
                stk.push(-num);
            } else if (op == '*')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top * num);
            } else if (op == '/')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top / num);
            }
            num = 0;
            op = token;
            if (token == ')')
                break;
        }
    }
    int ans = 0;
    while (!stk.empty())
    {
        ans +=stk.top();
        stk.pop();
    }
    return ans;
}
int calculate(string s) {
    int i = 0;
    return helper(s,i);
}