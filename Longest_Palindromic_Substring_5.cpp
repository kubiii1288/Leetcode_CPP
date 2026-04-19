//
// Created by Anh Le on 4/5/26.
//
string longestPalindrome(string& s)
{
    int bestLength = 0;
    int from = -1;
    for (int i = 0; i < s.size(); i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > bestLength)
            {
                from = l;
                bestLength = r-l+1;
            }
            l--;
            r++;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > bestLength)
            {
                from = l;
                bestLength = r-l+1;
            }
            l--;
            r++;
        }
    }
    return s.substr(from,bestLength);
}