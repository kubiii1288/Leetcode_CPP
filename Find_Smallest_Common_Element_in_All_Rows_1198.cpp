//
// Created by Anh Le on 8/28/26.
//
int smallestCommonElement(vector<vector<int>>& mat) {
    const int M = mat.size();
    int cnt[10001];
    for (vector<int> &v : mat)
    {
        for (int i : v)
            cnt[i]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (cnt[i] == M)
            return i;
    }
    return -1;
}