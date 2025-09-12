//
// Created by Anh Le on 9/11/25.
//
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
string sortVowels(string s) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    vector<char> v;
    for (char &c : s)
    {
        if (vowels.find(tolower(c)) != vowels.end())
        {
            v.push_back(c);
            c = '1';
        }
    }
    sort(v.begin(), v.end());
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            s[i] = v.back();
            v.pop_back();
        }
    }
    return s;
}