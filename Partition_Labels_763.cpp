//
// Created by Anh Le on 6/1/26.
//
vector<int> partitionLabels(string s) {
    int last[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        last[s[i] - 'a'] = i;
    }
    int start = 0, farthest = 0;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++)
    {
        farthest = max(farthest, last[s[i] - 'a']);
        if (i == farthest)
        {
            ans.push_back(farthest - start +1);
            start = farthest+1;
        }
    }
    return ans;
}