//
// Created by Anh Le on 8/28/26.
//

vector<vector<string>> groupStrings(vector<string>& strings) {
    map<vector<int>, vector<string>> mp;

    for (string &s : strings)
    {
        vector<int> v;
        for (int i = 1; i < s.size(); i++)
        {
            v.push_back((s[i] - s[i-1]+26) % 26);
        }
        mp[v].push_back(s);
    }
    vector<vector<string>> ans;
    for (auto &p : mp)
    {
        ans.push_back(std::move(p.second));
    }
    return std::move(ans);
}