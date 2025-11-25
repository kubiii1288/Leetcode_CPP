//
// Created by Anh Le on 3/11/25.
//
#include<iostream>
#include <unordered_set>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    if (ransomNote.size() > magazine.size()) return false;

    vector<int> map(26,0);

    for (char &c : magazine)
        map[c]++;

    for (char &c : ransomNote)
    {
        if (map[c] < 1) return false;
        map[c]--;
    }
    return true ;
}