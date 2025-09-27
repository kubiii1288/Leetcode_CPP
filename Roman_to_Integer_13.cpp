//
// Created by Anh Le on 9/24/25.
//
int romanToInt(string& s)
{
    unordered_map<char, int> map;
    map.insert({'I', 1});
    map.insert({'V', 5});
    map.insert({'X', 10});
    map.insert({'L', 50});
    map.insert({'C', 100});
    map.insert({'D', 500});
    map.insert({'M', 1000});
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && map[s[i]] < map[s[i + 1]])
        {
            ans -= map[s[i]];
        }
        else ans += map[s[i]];
    }
    return ans;
}
