//
// Created by Anh Le on 3/11/25.
//
#include <iostream>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> rs;
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
        {
            rs.push_back("FizzBuzz");
        } else if (i % 3 == 0)
        {
            rs.push_back("Fizz");
        } else if (i % 5 == 0)
        {
            rs.push_back("Buzz");
        } else
        {
            rs.push_back(to_string(i));
        }
    }
    return rs;
}