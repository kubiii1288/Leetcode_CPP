//
// Created by Anh Le on 9/18/26.
//

bool isDivisible(vector<int>& sweetness, int k, int target)
{
    int sum = 0;
    int pieces = 0;
    for (int x : sweetness)
    {
        sum += x;
        if (sum >= target)
        {
            sum = 0;
            pieces++;
        }
    }
    return pieces >= k + 1;
}
int maximizeSweetness(vector<int>& sweetness, int k) {
    int l = 1, r = std::accumulate(sweetness.begin(), sweetness.end(),0) / (k+1);
    while (l <= r)
    {
        int target = (l + r) /2;
        if (isDivisible(sweetness, k, target))
        {
            l = target+1;
        } else r = target-1;
    }
    return r;
}