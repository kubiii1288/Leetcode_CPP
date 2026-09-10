//
// Created by Anh Le on 5/17/26.
//
bool canReach(vector<int>& arr, int start)
{
    const int size = arr.size();
    vector<bool> visited(size, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        if (arr[u] == 0)
            return true;
        q.pop();
        int first = u + arr[u];
        int second = u - arr[u];
        if (0 <= first && first < size && !visited[first])
        {
            visited[first] = true;
            q.push(first);
        }
        if (0 <= second && second < size && !visited[second])
        {
            visited[second] = true;
            q.push(second);
        }
    }
    return false;
