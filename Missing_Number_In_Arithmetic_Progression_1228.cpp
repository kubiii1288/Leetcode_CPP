//
// Created by Anh Le on 9/23/26.
//
int missingNumber(vector<int>& arr) {
    int gap = (arr.back() - arr.front()) /(int) arr.size();
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[i-1] != gap)
            return arr[i] - gap;
    }
    return arr.front();
}