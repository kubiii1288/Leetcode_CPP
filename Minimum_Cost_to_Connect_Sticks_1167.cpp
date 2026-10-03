//
// Created by Anh Le on 9/15/26.
//
int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int &i : sticks)
        q.push(i);
    int cost = 0;
    while (q.size() > 1) {
        int currentCost = q.top();
        q.pop();
        currentCost += q.top();
        q.pop();
        cost += currentCost;
        q.push(currentCost);
    }
    return cost;
}

int connectSticks_2(vector<int>& sticks) {
    make_heap(sticks.begin(), sticks.end(), greater<int>());

    int cost = 0;
    while (sticks.size() > 1) {

        int current = sticks.front();
        pop_heap(sticks.begin(), sticks.end(), greater<int>());
        sticks.pop_back();

        current += sticks.front();
        pop_heap(sticks.begin(), sticks.end(), greater<int>());
        sticks.pop_back();

        cost += current;
        sticks.push_back(current);
        push_heap(sticks.begin(), sticks.end(), greater<int>());
    }
    return cost;
}