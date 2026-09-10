//
// Created by Anh Le on 8/22/26.
//
class StockSpanner {
public:

    stack<pair<int,int>> stk;
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while (stk.size() && stk.top().first <= price)
        {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price,span});
        return span;
    }
};

