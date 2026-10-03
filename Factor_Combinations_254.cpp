//
// Created by Anh Le on 9/25/26.
//
void back_track(vector<vector<int>> &ans, vector<int> &current)
{
    if (current.size() > 1)
    {
        ans.push_back(current);
        return;
    }
    const int lastFactor = current.back();
    current.pop_back();
    for (int i = current.empty() ? 2 : current.back(); i <= lastFactor/i; i++)
    {
        if (lastFactor % i == 0)
        {
            current.push_back(i);
            current.push_back(lastFactor % i);
            back_track(ans,current);
            current.pop_back();
            current.pop_back();
        }
    }
    current.push_back(lastFactor);
}
vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    vector<int> current = {n};
    back_track(ans, current);
    return ans;
}