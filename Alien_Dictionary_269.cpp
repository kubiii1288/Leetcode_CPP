//
// Created by Anh Le on 9/13/26.
//
string alienOrder(vector<string>& words)
{
    vector<unordered_set<int>> graph(26);
    vector<int> inDegree(26, 0);
    vector<bool> exist(26, false);
    int totalChars = 0;
    for (string& s : words)
        for (char c : s)
        {
            if (!exist[c - 'a'])
            {
                exist[c - 'a'] = true;
                totalChars++;
            }
        }
    for (int i = 0; i + 1 < words.size(); i++)
    {
        string& w1 = words[i];
        string& w2 = words[i + 1];
        int l1 = 0, l2 = 0;
        bool found = false;
        while (l1 < w1.size() && l2 < w2.size())
        {
            if (w1[l1] == w2[l2])
            {
                l1++;
                l2++;
                continue;
            }

            found = true;

            int u = w1[l1] - 'a';
            int v = w2[l2] - 'a';

            if (!graph[u].count(v))
            {
                graph[u].insert(v);
                inDegree[v]++;
            }

            break;
        }
        if (!found && w1.size() > w2.size()) return "";
    }
    queue<int> q;
    string ans;
    for (int i = 0; i < 26; i++)
    {
        if (exist[i] && inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        ans.push_back((u + 'a'));
        q.pop();
        for (int v : graph[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }
    if (totalChars != ans.size()) return "";
    return ans;
}