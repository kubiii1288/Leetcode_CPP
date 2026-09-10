//
// Created by Anh Le on 8/25/26.
//
void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());
    int start = 0;
    while (start < s.size()) {
        int end = start;
        while (end < s.size() && s[end] != ' ')
            end++;
        reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
    }
}