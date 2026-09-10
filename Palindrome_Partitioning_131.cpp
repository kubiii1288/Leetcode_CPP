//
// Created by Anh Le on 5/23/26.
//
bool isPalindrome(string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
void solve(string &s, int left, vector<vector<string>> &ans, vector<string> &partition)
{
    if (left >= s.size())
    {
        ans.push_back(std::move(partition));
        return;
    }
    for (int right = left; right < s.size(); right++)
    {
        if (isPalindrome(s, left, right))
        {
            partition.push_back(s.substr(left, (right-left+1)));
            solve(s,right+1,ans,partition);
            partition.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partition;
    solve(s,0,ans,partition);
    return ans;
}