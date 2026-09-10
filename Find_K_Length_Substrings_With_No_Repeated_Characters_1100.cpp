//
// Created by Anh Le on 8/26/26.
//
int numKLenSubstrNoRepeats(string &s, int k) {
    int l = 0, r = 0;
    int mp[256] = {0};
    int ans = 0;
    for (; r < s.size(); r++)
    {
        mp[s[r]]++;
        while (mp[s[r]] > 1 || r - l +1 > k)
        {
            mp[s[l]]--;
            l++;
        }
        if (r- l +1 == k)
            ans++;
    }
    return ans;
}