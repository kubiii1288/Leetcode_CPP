//
// Created by Anh Le on 8/31/26.
//
string addBoldTag(string &s, vector<string>& words) {
    string ans;
    const static string OPEN = "<b>";
    const static string CLOSE = "</b>";
    const int n = s.size();
    int end = 0;
    vector<bool> valid(n,false);
    for (int i = 0; i < n; i++)
    {
        for (string &w : words)
        {
            int len = w.size();
            if (i + len <= n && s.compare(i,len,w) == 0)
                end = max(end,i +len);
        }
        valid[i] = i < end;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (valid[i] && (i == 0 || !valid[i-1]))
            ans.append(OPEN);
        ans.push_back(s[i]);
        if (valid[i] && ((i == n-1) ||  !valid[i+1]))
            ans.append(CLOSE);
    }
    return ans;
}