//
// Created by Anh Le on 3/19/25.
//

#include <iostream>
#include <set>
using namespace std;

int thirdMax(vector<int>& nums)
{
    set<int> s;

    for (int i : nums)
    {
        s.insert(i);
    }

    if (s.size() < 3) return *prev(s.end());

    s.erase(prev(s.end()));
    s.erase(prev(s.end()));
    return *prev(s.end());
}
