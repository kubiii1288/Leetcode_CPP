//
// Created by Anh Le on 10/10/25.
//
int rangeBitwiseAnd(int left, int right) {
    int cnt = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        cnt++;
    }
    return (left << cnt);
}