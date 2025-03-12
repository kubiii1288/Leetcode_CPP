//
// Created by Anh Le on 3/11/25.
//
#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int max_balance = -1;
    for (const vector<int> &account : accounts)
    {
        int sum = 0;
        for (const int &balance : account)
        {
           sum+= balance;
        }
        max_balance = std::max(max_balance, sum);
    }
    return max_balance;
}