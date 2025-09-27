//
// Created by Anh Le on 9/24/25.
//
string intToRoman(int num)
{
    string ans;
    vector<pair<int, string>> v = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int time = num / v[i].first;
        while (time-- > 0)
        {
            ans.append(v[i].second);
        }
        num = num % v[i].first;
    }
    return ans;
}
