//
// Created by Anh Le on 8/14/26.
//
int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = 1e9;

    while (l < r) {
        int speed = l + (r - l) / 2;
        int total = 0;
        for (int banana : piles)
            total += (banana + speed - 1) / speed;
        if (total > h) {
            l = speed + 1;
        } else
            r = speed;
    }
    return r;
}