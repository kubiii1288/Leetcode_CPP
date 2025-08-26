//
// Created by Anh Le on 3/21/25.
//
#include <iostream>
using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> temp = heights;
    sort(temp.begin(), temp.end());
    int cnt = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (temp[i] != heights[i]) cnt++;
    }
   return cnt;
}