//
// Created by Anh Le on 9/30/25.
//

int numWaterBottles(int numBottles, int numExchange) {
    int ans = 0;
    int drinkable = numBottles;
    int empty = 0;
    while (drinkable > 0) {
        ans += drinkable;
        empty += drinkable;
        drinkable = empty / numExchange;
        empty = empty % numExchange;
    }
    return ans;
}