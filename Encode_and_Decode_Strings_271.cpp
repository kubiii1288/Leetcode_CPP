//
// Created by Anh Le on 9/21/26.
//
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (string &s : strs)
        {
            ans.append(to_string(s.size()));
            ans.push_back('#');
            ans.append(s);
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int l = 0, r;
        vector<string> ans;
        while (l < s.size())
        {
            r = s.find('#', l);
            int size = stoi(s.substr(l,(r-l)));
            string temp = s.substr(r+1,size);
            ans.push_back(temp);
            l = r + size + 1;
        }
        return ans;
    }
};