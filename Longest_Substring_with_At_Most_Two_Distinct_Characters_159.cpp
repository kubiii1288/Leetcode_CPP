//
// Created by Anh Le on 8/25/26.
//
int lengthOfLongestSubstringTwoDistinct(string s) {
    int l = 0, r = 0;
    int k = 2;
    int ans = 0;
    int mp[256] = {0};
    int unique = 0;
    for (; r < s.size(); r++) {
        mp[s[r]]++;
        if (mp[s[r]] == 1)
            unique++;
        while (unique > k) {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                unique--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}