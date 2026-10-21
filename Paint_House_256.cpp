//
// Created by kubiii on 10/18/26.
//
#define RED 0
#define GREEN 1
#define BLUE 2
int minCost(vector<vector<int>>& costs) {
    const int n = costs.size();
    int red = 0;
    int green = 0;
    int blue = 0;
    for (int i = 0; i < n; i++) {
        int r = costs[i][RED] + std::min(green, blue);
        int g = costs[i][GREEN] + std::min(red, blue);
        int b = costs[i][BLUE] + std::min(red, green);
        red = r;
        green = g;
        blue = b;
    }
    return std::min({red,green,blue});
}