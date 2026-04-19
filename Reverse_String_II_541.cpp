//
// Created by Anh Le on 4/12/26.
//
string reverseStr(string &s, int k) {
    for (int i = 0; i < s.size(); i+= 2*k)
    {
        reverse(s.begin() + i, s.begin() + std::min(i+k, (int)s.size()));
    }
    return s;
}