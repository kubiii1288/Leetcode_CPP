//
// Created by Anh Le on 9/13/25.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
unordered_map<char, int> char_map;

bool is_vowel(char c)
{
    return vowels.find(c) != vowels.end();
}

int maxFreqSum(string s)
{
    int max_vowel = 0;
    int max_consonant = 0;

    for (char c : s)
    {
        if (is_vowel(c))
        {
            if (char_map.find(c) == char_map.end())
            {
                char_map[c] = 1;
            }
            else
            {
                char_map[c]++;
            }
            max_vowel = max(max_vowel, char_map[c]);
        }
        else
        {
            if (char_map.find(c) == char_map.end())
            {
                char_map[c] = 1;
            }
            else
            {
                char_map[c]++;
            }
            max_consonant = max(max_consonant, char_map[c]);
        }
    }
    return max_consonant + max_vowel;
}
