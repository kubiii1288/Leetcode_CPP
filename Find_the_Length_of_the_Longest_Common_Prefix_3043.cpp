//
// Created by Anh Le on 5/21/26.
//
int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<string> us;
    for (int i : arr1)
    {
        string current = to_string(i);
        string prefix;
        for (char c : current)
        {
            prefix.push_back(c);
            us.insert(prefix);
        }
    }
    size_t best = 0;
    for (int i : arr2)
    {
        string current = to_string(i);
        string prefix;
        for (char c : current)
        {
            prefix.push_back(c);
            if (us.count(prefix) > 0)
            {
                best = max(best, prefix.size());
            }
        }
    }
    return best;
}