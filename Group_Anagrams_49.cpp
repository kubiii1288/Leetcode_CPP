//
// Created by Anh Le on 10/8/25.
//
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> pairs;
    for (string& s : strs) {
        string temp = s;
        sort(s.begin(), s.end());
        pairs[s].push_back(move(temp));
    }

    for (unordered_map<string, vector<string>>::iterator it = pairs.begin();
         it != pairs.end(); ++it) {
        ans.push_back(move(it->second));
         }
    return ans;
}