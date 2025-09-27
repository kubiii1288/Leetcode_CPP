//
// Created by Anh Le on 3/20/25.
//

#include <iostream>
using namespace std;

bool validMountainArray(vector<int>& arr)
{
    if (arr.size() < 3) return false;
    int a = 0, b = arr.size() - 1;
    while (a < arr.size() - 1 && arr[a + 1] <= arr[a]) a++;
    while (b > 0 && arr[b - 1] <= arr[b]) b--;
    return a == b && a != arr.size() - 1 && b != 0;
}
