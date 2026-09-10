string gcdOfStrings(string s1, string s2) {
    if (s1.size() > s2.size())
        swap(s1, s2);
    int l1 = s1.size(), l2 = s2.size();
    for (int len = l1; len > 0; len--) {
        string ans = s1.substr(0, len);
        if (l1 % len || l2 % len)
            continue;
        int r1 = l1 / len;
        int r2 = l2 / len;

        string temp = ans;
        int r = 1;
        while (r < r1) {
            temp.append(ans);
            r++;
        }
        if (temp != s1)
            continue;
        while (r < r2) {
            temp.append(ans);
            r++;
        }
        if (temp != s2)
            continue;
        return ans;
    }

    return "";
}

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b%a,a);
}
string gcdOfStrings(string s1, string s2) {
    if (s1 + s2 != s2 + s1)
        return "";
    return s1.substr(0, gcd(s1.size(),s2.size()));
}