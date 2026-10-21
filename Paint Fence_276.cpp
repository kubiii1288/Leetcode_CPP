//
// Created by kubiii on 10/6/26.
//

int numWays(int n, int k) {
    if (n == 0) return 0;
    if (n == 1) return k;
    int diff = k * (k-1);
    int same = k;
    for (int i = 3; i <= n; i++) {
        int prevDiff = diff;
        diff = (same + diff) * (k-1);
        same = prevDiff;
    }
    return diff + same;
}