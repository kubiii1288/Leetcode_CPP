//
// Created by kubiii on 10/19/26.
//
int minSwaps(string s) {
    string stk;
    for (char c : s) {
        if (c == ']' && !stk.empty() && stk.back() == '[') {
            stk.pop_back();
        } else
            stk.push_back(c);
    }
    if (stk.size() % 2)
        return -1;
    int k = stk.size() / 2;
    return (k + 1) / 2;
}