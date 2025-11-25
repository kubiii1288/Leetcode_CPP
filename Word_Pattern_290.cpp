//
// Created by Anh Le on 10/8/25.
//
bool wordPattern(string& pattern, string& s) {
    unordered_map<char, string> map_char;
    unordered_map<string, char> map_string;
    vector<string> strs;
    stringstream ss(s);
    string temp;
    while (ss >> temp) {
        strs.push_back(temp);
    }
    if (pattern.size() != strs.size())
        return false;
    for (int i = 0; i < pattern.size(); i++) {
        if (map_char.find(pattern[i]) == map_char.end() &&
            map_string.find(strs[i]) == map_string.end()) {
            map_char[pattern[i]] = strs[i];
            map_string[strs[i]] = pattern[i];
            } else if (map_char.find(pattern[i]) == map_char.end() ^
                       map_string.find(strs[i]) == map_string.end()) {
                return false;
                       } else {
                           if (map_char[pattern[i]] != strs[i])
                               return false;
                       }
    }
    return true;
}