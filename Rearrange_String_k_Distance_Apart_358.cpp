//
// Created by Anh Le on 9/18/26.
//

string rearrangeString(string s, int k) {
    vector<int> freq(26,0);
    for (char c : s)
        freq[c-'a']++;

    priority_queue<pair<int,int>> free;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i])
            free.push({freq[i], i});
    }
    queue<pair<int,int>> busy;
    string ans;
    ans.reserve(s.size());
    while (ans.size() != s.size())
    {
        int index = ans.size();
        if (!busy.empty() && index - busy.front().first >= k)
        {
            free.push({freq[busy.front().second], busy.front().second});
            busy.pop();
        }
        if (free.empty())
            return "";
        int currentChar = free.top().second;
        free.pop();
        ans.push_back(currentChar + 'a');
        freq[currentChar]--;
        if (freq[currentChar] > 0)
            busy.push({index, currentChar});
    }
    return ans;
}