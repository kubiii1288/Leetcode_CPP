//
// Created by Anh Le on 9/30/25.
//
string longestCommonPrefix(vector<string>& strs) {
    string ans;
    for (int i = 0; i < strs[0].size(); i++) {
        for (string& s : strs) {
            if (s[i] != strs[0][i])
                return ans;
        }
        ans += strs[0][i];
    }
    return ans;
}