//
// Created by Anh Le on 7/20/26.
//
vector<int> findAnagrams(string s, string p) {
    vector<int> have(26,0);
    vector<int> need(26,0);
    vector<int> ans;
    for (char c : p)
        need[c-'a']++;
    int N = p.size();
    for (int i = 0; i < s.size(); i++)
    {
        have[s[i]-'a']++;
        if (i >= N-1)
        {
            if (have == need)
                ans.push_back(i - N +1);
            have[s[i-N+1] - 'a']--;
        }
    }
    return ans;
}