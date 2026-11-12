//
// Created by kubiii on 10/22/26.
//
bool makePalindrome(string s) {
    int l = 0, r = s.size()-1;
    int change = 0;
    while (l < r) {
        if (s[l++] != s[r--]) {
            change++;
        }
        if (change > 2) return false;
    }
    return true;
}