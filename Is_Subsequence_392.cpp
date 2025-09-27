//
// Created by Anh Le on 9/25/25.
//

bool isSubsequence(string& s, string& t)
{
    if (s.size() > t.size()) return false;
    int p_s, p_t;
    p_s = p_t = 0;
    while (p_t < t.size())
    {
        if (s[p_s] == t[p_t])
            p_s++;
        p_t++;
    }
    return p_s == s.size();
}
