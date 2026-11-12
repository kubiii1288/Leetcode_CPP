//
// Created by kubiii on 10/22/26.
//
int minimumKeypresses(string& s) {
    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;
    sort(freq.begin(), freq.end(), greater<int>());
    int presses = 0;
    for (int i = 0; i < 26; i++) {
        presses += (freq[i] * (i / 9+1));
    }
    return presses;
}