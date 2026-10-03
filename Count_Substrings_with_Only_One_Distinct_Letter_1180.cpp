//
// Created by Anh Le on 9/24/26.
//

int countLetters(string &s) {
    int l = 0, r= 0;
    int ans = 0;
    for (; r < s.size(); r++)
    {
        if (s[l] == s[r]) continue;
        int len = r - l;
        ans += (len * (len + 1)) / 2;
        l = r;
    }
    int len = r - l;
    ans += (len * (len + 1)) / 2;
    return ans;
}