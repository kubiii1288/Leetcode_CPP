//
// Created by Anh Le on 9/17/26.
//
int getIndex(ArrayReader& reader) {
    int l = 0, y = reader.length()-1;
    while (l < y) {
        int mid = (l + y) / 2;
        int r, x;
        if ((y - l + 1) % 2) {
            r = mid - 1;
        } else {
            r = mid;
        }
        x = mid + 1;
        int rs = reader.compareSub(l, r, x, y);
        if (rs == 1) {
            y = r;
        } else if (rs == -1) {
            l = x;
        } else
            return mid;
    }
    return l;
