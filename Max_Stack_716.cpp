//
// Created by Anh Le on 9/19/26.
//
class MaxStack {
public:
    list<int> stk;
    map<int, vector<list<int>::iterator>> maxStk;
    MaxStack() {
    }

    void push(int x) {
        stk.push_back(x);
        list<int>::iterator it = prev(stk.end());
        maxStk[x].push_back(it);
    }

    int pop() {
        int x = stk.back();
        stk.pop_back();
        auto it = maxStk.find(x);
        it->second.pop_back();
        if (it->second.empty())
            maxStk.erase(x);
        return x;
    }

    int top() {
        return stk.back();
    }

    int peekMax() {
        return maxStk.rbegin()->first;
    }

    int popMax() {
        auto maxIt = prev(maxStk.end());
        int rs = maxIt->first;
        stk.erase(maxIt->second.back());
        maxIt->second.pop_back();
        if (maxIt->second.empty())
            maxStk.erase(maxIt);
        return rs;
    }
};