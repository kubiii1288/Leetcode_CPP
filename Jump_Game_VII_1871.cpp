//
// Created by Anh Le on 5/25/26.
//
bool canReach(string s, int minJump, int maxJump) {
    const int n = s.size();
    vector<bool> visited(n,false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int farthest = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        int start = max(farthest+1, i + minJump);
        int end = min(i+ maxJump, n-1);
        for (int j = start; j <= end; j++)
        {
            if (s[j] == '0' && !visited[j])
            {
                if (j == n-1)
                    return true;
                visited[j] = true;
                q.push(j);
            }
        }
        farthest = end;
    }
    return visited[n-1];
}