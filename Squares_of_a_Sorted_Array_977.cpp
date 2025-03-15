//
// Created by Anh Le on 3/12/25.
//

#include <iostream>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans = nums;
    for (int &i : ans)
    {
        i = i * i;
    }
    sort(ans.begin(), ans.end());
    return ans;
}