//
// Created by Anh Le on 8/14/26.
//
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> ans;
    ans.reserve(spells.size());
    sort(potions.begin(), potions.end());
    for (long long s : spells)
    {
        int l = 0;
        int r = potions.size() -1;
        int mid;
        while (l <= r)
        {
            mid = (l+r) /2;
            long long p = potions[mid];
            if (s * p >= success)
            {
                r = mid-1;
            } else l = mid +1;
        }
        ans.push_back(potions.size()-l);
    }
    return std::move(ans);
}