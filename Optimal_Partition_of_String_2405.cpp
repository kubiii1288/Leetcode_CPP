//
// Created by kubiii on 10/20/26.
//


int partitionString(string s) {
    vector<int> mp(26,0);
    int l = 0, r = 0;
    int ans = 0;
    for (;r < s.size(); r++) {
        if (mp[s[r]-'a']) {
            ans++;
            while (l < r)
                mp[s[l++]-'a']--;
        } mp[s[r]-'a']++;
    }
    return ans+1;
}
