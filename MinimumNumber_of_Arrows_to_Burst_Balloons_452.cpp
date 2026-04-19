//
// Created by Anh Le on 11/26/25.
//
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int start = points[0][0];
    int end = points[0][1];
    int ans = 1;
    for (int i = 1; i < points.size(); i++) {
        if (start <= points[i][0] && points[i][0] <= end) {
            start = max(points[i][0], start);
            end = min(points[i][1], end);
        } else {
            ans++;
            start = points[i][0];
            end = points[i][1];
        }
    }
    return ans;
}