//
// Created by Anh Le on 9/1/26.
//
string parseTernary(string expression) {
    string ans;
    stack<char> stk;
    for (int i = expression.size()-1; i >= 0; i--)
    {
        char token = expression[i];
        if (token != ':' && token != '?')
        {
            stk.push(token);
        } else if (token == '?')
        {
            i--;
            bool predicate = (expression[i] == 'T');
            if (predicate)
            {
                char value = stk.top();
                stk.pop();
                stk.pop();
                stk.push(value);
            } else stk.pop();
        }
    }
    ans = stk.top();
    return ans;
}