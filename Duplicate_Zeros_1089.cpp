//
// Created by Anh Le on 3/12/25.
//
#include <iostream>
using namespace std;

// Input: arr = [1,0,2,3,0,4,5,0]
// Output: [1,0,0,2,3,0,0,4]

void duplicateZeros(int arr[], int arrSize) {
    const int size = arrSize;
    int i = 0;
    while (i < size)
    {
        int zeros = 0;
        while (i < size && arr[i] == 0)
        {
            zeros++;
            i++;
        }
        for (int j = size -1; j >= i+zeros; j--)
        {
            arr[j] = arr[j-zeros];
        }
        for (int j = 0; j < zeros; j++)
        {
            if (i+j <= size -1)
                arr[i+j] = 0;
        }

        i+= zeros > 0 ? zeros : 1;
    }
}

