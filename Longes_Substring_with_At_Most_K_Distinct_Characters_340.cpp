//
// Created by Anh Le on 8/26/26.
//

int lengthOfLongestSubstringKDistinct(string &s, int k) {
    int l = 0, r= 0;
    int mp[256] = {0};
    int unique = 0;
    int maxLen = 0;

    for (; r < s.size(); r++)
    {
        mp[s[r]]++;
        if (mp[s[r]] == 1)
            unique++;
        while (unique > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                unique--;
            l++;
        }
        if (unique <= k)
            maxLen = max(maxLen, r- l +1);
    }
    return maxLen;
}