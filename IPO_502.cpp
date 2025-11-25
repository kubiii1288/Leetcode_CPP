//
// Created by Anh Le on 11/8/25.
//

struct Project {
    int profit, capital;
};

struct comp_profit {
    bool operator()(Project& a, Project& b) { return a.profit < b.profit; }
};

struct comp_capital {
    bool operator()(Project& a, Project& b) {
        return a.capital > b.capital;
    }
};
int findMaximizedCapital(int k, int w, vector<int>& profits,
                         vector<int>& capital) {
    priority_queue<Project, vector<Project>, comp_profit> max_heap;
    priority_queue<Project, vector<Project>, comp_capital> min_heap;

    for (int i = 0; i < profits.size(); i++) {
        min_heap.push({profits[i], capital[i]});
    }
    while (k-- > 0) {
        while (!min_heap.empty() && min_heap.top().capital <= w) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if (max_heap.empty())
            break;
        w += max_heap.top().profit;
        max_heap.pop();
    }
    return w;
}