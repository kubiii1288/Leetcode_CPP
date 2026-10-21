//
// Created by kubiii on 10/21/26.
//
int minSwaps(vector<int>& data) {
    int windowSize = accumulate(data.begin(), data.end(),0);
    int l = 0, r= 0;
    int countZero= 0;
    const int n = data.size();
    while (r < windowSize) {
        countZero+= !data[r++];
    }
    int ans = countZero;
    while (r < n) {
        countZero += !data[r++];
        countZero -= !data[l++];
        ans = min(ans,countZero);
    }
    return ans;
}