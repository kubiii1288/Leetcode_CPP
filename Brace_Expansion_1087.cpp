//
// Created by Anh Le on 9/25/26.
//

void solve(vector<string> &ans, vector<vector<char>> &dict, string &current, int index)
{
    if (index >= dict.size())
    {
        ans.push_back(current);
        return;
    }

    for (char c : dict[index])
    {
        current[index] = c;
        solve(ans,dict,current,index+1);
    }
}
vector<string> expand(string &s) {
    vector<vector<char>> dict;
    vector<string> ans;
    int l = 0, r = 0;
    while (l < s.size())
    {
        if ( 'a' <= s[l] && s[l] <= 'z')
        {
            dict.push_back({s[l]});
        } else if (s[l] == '{')
        {
            vector<char> v;
            for (r = l + 1; r < s.size() && s[r] != '}'; r++)
            {
                if (s[r] != ',')
                    v.push_back(s[r]);
            }
            sort(v.begin(), v.end());
            dict.push_back(std::move(v));
            l = r;
        }
        l++;
    }
    string current(dict.size(),' ');
    solve(ans,dict,current,0);
    return ans;
}