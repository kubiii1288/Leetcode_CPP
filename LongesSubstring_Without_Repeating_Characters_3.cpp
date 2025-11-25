//
// Created by Anh Le on 9/28/25.
//
int lengthOfLongestSubstring(string& s)
{
    // unordered_map<char, int> map;
    vector<int> map(256, 0);
    int left = 0;
    int right = 0;
    int max_len = -1;
    while (right < s.size())
    {
        map[s[right]]++;

        if (map[s[right]] == 1)
        {
            if (max_len < right - left + 1)
            {
                max_len = right - left + 1;
            }
        }
        else
        {
            while (s[left] != s[right])
            {
                map[s[left]]--;
                left++;
            }
            map[s[left]]--;
            left++;
        }
        right++;
    }
    return std::max(max_len, 0);
}
