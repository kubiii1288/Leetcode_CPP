//
// Created by Anh Le on 4/3/26.
//
string minWindow(string& s, string& t) {
    if (s.size() < t.size())
        return "";
    const int M = s.size();
    const int N = t.size();
    int have[256] = {0};
    int need[256] = {0};
    int matchedChars = 0;
    for (char c : t)
        need[c]++;

    int bestLen = 1e6;
    int from = -1, to = -1;

    int left = 0, right = 0;
    while (right < M) {
        char rightChar = s[right];
        have[rightChar]++;
        if (have[rightChar] <= need[rightChar])
            matchedChars++;
        while (matchedChars == N) {
            int current_size = right - left + 1;
            if (current_size == N)
                return s.substr(left, current_size);
            if (current_size < bestLen) {
                from = left;
                to = right;
                bestLen = current_size;
            }
            char leftChar = s[left];
            have[leftChar]--;
            if (have[leftChar] < need[leftChar])
                matchedChars--;
            left++;
        }
        right++;
    }
    if (to != -1)
        return s.substr(from, bestLen);
    return "";
}