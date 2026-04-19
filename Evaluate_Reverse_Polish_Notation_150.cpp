//
// Created by Anh Le on 4/4/26.
//
bool is_operator(string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}
int evalRPN(vector<string>& tokens) {
    vector<int> stack;
    for (string &token: tokens)
    {
        if (is_operator(token))
        {
            int second = stack.back();
            stack.pop_back();
            int first = stack.back();
            stack.pop_back();
            if (token == "+")
                stack.push_back(first + second);
            else if (token == "-")
                stack.push_back(first -second);
            else if (token == "*")
                stack.push_back(first * second);
            else stack.push_back(first/second);
        } else
        {
            stack.push_back(stoi(token));
        }
    }
    return stack.back();
}