//
// Created by Anh Le on 9/11/25.
//

#include <iostream>
#include <set>
using namespace std;
set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
bool is_vowel(char c)
{
    return vowels.find(c) != vowels.end();
}
string reverseVowels(string s) {
    int i = 0;
    int j = s.size() -1;
    while (i < s.size() && j >= 0 && i < j)
    {
       while (i < s.size() && !is_vowel(s[i]))
           i++;
       while (j >= 0 && !is_vowel(s[j]))
           j--;
       std::swap(s[i],s[j]);
    }
    return s;
}