//
// Created by Anh Le on 8/7/26.
//

int compress(vector<char>& chars) {
    string ans;
    ans.reserve(chars.size());
    int cnt = 1;
    ans.push_back(chars[0]);
    for (int i = 1; i < chars.size(); i++)
    {
        char c = chars[i];
        if (c == ans.back())
        {
            cnt++;
        } else
        {
            if (cnt > 1)
            {
                ans.append(to_string(cnt));
            }
            cnt = 1;
            ans.push_back(c);
        }
    }
    if (cnt > 1)
        ans.append(to_string(cnt));
    chars.clear();
    for(char c : ans)
    {
        chars.push_back(c);
    }
    chars.assign(ans.begin(), ans.end());

    return ans.size();
}