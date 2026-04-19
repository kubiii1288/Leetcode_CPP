//
// Created by Anh Le on 4/3/26.
//
class MinStack {
public:
    vector<int> s;
    vector<int> min;
    MinStack() {

    }

    void push(int val) {
        s.push_back(val);
        if (min.empty())
        {
            min.push_back(val);
        } else if (min.back() >= val) {
            min.push_back(val);
        }
    }

    void pop() {
        if (!s.empty())
        {
            if (s.back() == min.back())
                min.pop_back();
            s.pop_back();
        }
    }

    int top() {
        return s.back();
    }

    int getMin() {
        return min.back();
    }
};