//
// Created by Anh Le on 8/25/26.
//

int shortestWay(string source, string target) {
    int cntSource[26] = {0};
    int cntTarget[26] = {0};
    for (char c : source)
        cntSource[c - 'a']++;
    for (char c : target)
        cntTarget[c - 'a']++;
    for (int i = 0; i < 26; i++)
        if (cntTarget[i] > 0 && cntSource[i] == 0) return -1;

    int pt = 0, ans= 0;
    while (pt < target.size())
    {
        for (int ps = 0; ps < source.size() && pt < target.size(); ps++)
        {
            if (source[ps] == target[pt])
                pt++;
        }
        ans++;
    }
    return ans;
}