//
// Created by Anh Le on 10/17/25.
//
void generate(string& digits, int index, map<char, string>& hash, string& current, vector<string>& ans)
{
    if (index == digits.size())
    {
        ans.push_back(current);
        return;
    }
    for (int i = 0; i < hash[digits[index]].size(); i++)
    {
        current.push_back(hash[digits[index]][i]);
        generate(digits, index + 1, hash, current, ans);
        current.pop_back();
    }
}

vector<string> letterCombinations(string& digits)
{
    vector<string> ans;
    map<char, string> map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    string current;
    generate(digits, 0, map, current, ans);
    return ans;
}
