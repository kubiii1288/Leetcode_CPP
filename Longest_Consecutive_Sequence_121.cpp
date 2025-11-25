//
// Created by Anh Le on 10/9/25.
//
int maxProfit(vector<int>& prices) {
    int min_price, max_price, min_index, max_index;
    min_price = max_price = prices[0];
    min_index = max_index = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > max_price && i >= min_index) {
            max_price = prices[i];
            max_index = i;
        }

        if (prices[i] < min_price && i < max_index) {
            min_price = prices[i];
            min_index = i;
        }
    }

    return max_price - min_price;
}