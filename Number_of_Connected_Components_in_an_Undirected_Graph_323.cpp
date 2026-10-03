//
// Created by Anh Le on 9/11/26.
//

int findParent(vector<int> &dsu, int v)
{
    if (v == dsu[v]) return v;
    return dsu[v] = findParent(dsu,dsu[v]);
}

void unionSet(vector<int> &dsu, int a, int b)
{
    a = findParent(dsu,a);
    b = findParent(dsu,b);
    if (a != b)
        dsu[b] = a;
}

int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> dsu(n);
    std::iota(dsu.begin(), dsu.end(),0);
    for (vector<int> e : edges)
        unionSet(dsu, e[0], e[1]);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsu[i] == i)
            ans++;
    }
    return ans;
}