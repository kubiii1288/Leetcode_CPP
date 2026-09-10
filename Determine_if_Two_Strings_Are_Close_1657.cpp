//
// Created by Anh Le on 8/8/26.
//


bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;
    unordered_map<char,int> mp1, mp2;
    unordered_map<int,int> freq1,freq2;
    unordered_set<char> s1,s2;
    for (char c : word1)
    {
        mp1[c]++;
        s1.insert(c);
    }
    for (char c : word2)
    {
        mp2[c]++;
        s2.insert(c);
    }

    for (const pair<char,int> &p : mp1)
        freq1[p.second]++;
    for (const pair<char,int> &p : mp2)
        freq2[p.second]++;
    return s1 == s2 && ( mp1 == mp2 || freq1 == freq2);
}

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;

    vector<int> freq1(26,0);
    vector<int> freq2(26,0);

    for (char c : word1)
        freq1[c-'a']++;
    for (char c : word2)
        freq2[c-'a']++;
    for (int i = 0; i < 26; i++)
    {
        if ((freq1[i] == 0 && freq2[i] >0) || (freq1[i] >0 && freq2[i] == 0))
            return false;
    }
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    return freq1 == freq2;
}