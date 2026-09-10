//
// Created by Anh Le on 5/21/26.
//

int maxProduct(vector<int>& nums) {
    int currentMax = nums[0];
    int currentMin = nums[0];
    int best = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int x = nums[i];
        int prevMax = currentMax;
        int prevMin = currentMin;
        currentMax = std::max({x, x * prevMax, x * prevMin});
        currentMin = std::min({x, x * prevMax, x * prevMin});
        best = max(best, currentMax);
    }
    return best;
}