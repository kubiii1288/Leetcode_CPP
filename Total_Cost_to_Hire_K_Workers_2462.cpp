//
// Created by Anh Le on 8/14/26.
//

long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<int,vector<int>, greater<int>> left;
    priority_queue<int,vector<int>, greater<int>> right;

    int l= 0;
    int r = costs.size()-1;
    for (int i = 0; i < candidates && l <= r; i++)
    {
        left.push(costs[l]);
        l++;
    }

    for (int i = 0; i < candidates && l <= r; i++)
    {
        right.push(costs[r]);
        r--;
    }

    long long total = 0;
    for (int i = 0; i < k; i++)
    {
        if (right.empty() || (left.size() && left.top() <= right.top()))
        {
            total += left.top();
            left.pop();
            if (l <= r)
                left.push(costs[l++]);
        } else
        {
            total += right.top();
            right.pop();
            if (l <= r)
                right.push(costs[r--]);
        }
    }
    return total;
}
