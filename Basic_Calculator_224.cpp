//
// Created by Anh Le on 4/4/26.
//
int calculate(string s) {
    int ans = 0;
    int sign = 1;
    vector<int> stack;
    int N = s.length();

    for (int i = 0; i < N; i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            int current = 0;
            while (i < N && isdigit(s[i]))
            {
                current = current *10 + (s[i] - '0');
                i++;
            }
            i--;
            ans += sign *current;
        } else if (c == '+')
        {
            sign = 1;
        } else if (c == '-')
        {
            sign = -1;
        } else if (c == '(')
        {
            stack.push_back(ans);
            stack.push_back(sign);
            ans = 0;
            sign = 1;
        } else if (c == ')')
        {
            int prevSign =  stack.back(); stack.pop_back();
            int prevAns=  stack.back(); stack.pop_back();

            ans = prevAns + ans*prevSign;
        }
    }
    return ans;
}