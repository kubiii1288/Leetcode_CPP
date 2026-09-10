//
// Created by Anh Le on 5/3/26.
//
string longestPalindrome(string s) {
    int l = 0;
    int bestLength = 1;

    for (int i = 0; i < s.size(); i++)
    {
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (bestLength < right -left  - 1)
        {
            bestLength = right - left - 1;
            l = left+1;
        }
        left = i;
        right = i+1;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (bestLength < right -left  - 1)
        {
            bestLength = right - left - 1;
            l = left+1;
        }
    }
    return s.substr(l,bestLength);
}