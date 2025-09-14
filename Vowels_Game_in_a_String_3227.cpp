//
// Created by Anh Le on 9/11/25.
//

#include <iostream>
#include <set>
using namespace std;


bool doesAliceWin(string s)
{
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (char& c : s)
    {
        if (vowels.find(c) != vowels.end())
            return true;
    }

    return false;
}
