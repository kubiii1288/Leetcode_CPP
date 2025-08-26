//
// Created by Anh Le on 3/16/25.
//
#include <iostream>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    const int size = arr.size();
    vector<int> rs(size);
    rs[size -1] = -1;
    for (int i = size -2; i >= 0; i--)
    {
        rs[i] = std::max(arr[i+1], rs[i+1]);
    }
    return rs;
}