//
// Created by Anh Le on 9/18/25.
//

static bool both_are_space(char l, char r) { return (l == r) && (r == ' '); }
string reverseWords(string& s) {
    // trim left
    int left = 0;
    while (s[left] == ' ')
        left++;
    s.erase(0, left);
    // trim right
    int right = s.size() - 1;
    while (s[right] == ' ')
        right--;
    s.erase(right + 1, s.size());
    // replace multiple spaces with one space
    string::iterator new_end =
        std::unique(s.begin(), s.end(), both_are_space);
    s.erase(new_end, s.end());
    reverse(s.begin(), s.end());
    left = right = 0;

    while (left < s.size() && right < s.size()) {
        while (right < s.size() && s[right] != ' ')
            right++;
        reverse(s.begin() + left, s.begin() + right);
        right++;
        left = right;
    }
    return s;
}