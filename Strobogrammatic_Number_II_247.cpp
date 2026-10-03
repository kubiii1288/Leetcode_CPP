//
// Created by Anh Le on 9/22/26.
//

vector<pair<char,char>> pool = {
    {'0','0'},
    {'1','1'},
    {'8', '8'},
    {'6','9'},
    {'9', '6'}
};

vector<char> poolMiddle = { '0', '1', '8' };
void backtrack(vector<string> &ans , string &number, int l , int r)
{
    if (l > r)
    {
        ans.push_back(number);
        return;
    }
    if (l == r)
    {
        for (int i = 0; i < 3; i++)
        {
            number[l] = poolMiddle[i];
            backtrack(ans, number, l+1, r-1);
        }
        return;
    }
    for (int i = 0; i < pool.size(); i++)
    {
        if (l == 0 && pool[i].first == '0') continue;
        number[l] = pool[i].first;
        number[r] = pool[i].second;
        backtrack(ans,number, l+1, r-1);
    }
}
vector<string> findStrobogrammatic(int n) {
    vector<string> ans;
    string number(n,' ');
    backtrack(ans, number,0, n-1);
    return ans;
}