//
// Created by Anh Le on 9/12/26.
//
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int getHash(int r, int c, const int N)
{
    return r * N + c;
}

int find_set(vector<int> &parent, int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent, parent[v]);
}
bool union_set(vector<int> &parent, int a, int b)
{
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}
vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    const int size = m * n;
    vector<int> parent(size);
    for (int i = 0; i < size; i++)
        parent[i] = -1;
    vector<int> ans;
    int islands = 0;
    for (vector<int> &v : positions)
    {
        int currentHash = getHash(v[0], v[1],n);
        if (parent[currentHash] != -1)
        {
            ans.push_back(islands);
            continue;
        }
        islands++;
        parent[currentHash] = currentHash;
        int x = v[0];
        int y = v[1];
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (0 <= xx && xx < m && 0 <= yy && yy < n)
            {
                int neighborHash = getHash(xx,yy,n);
                if (parent[neighborHash] != -1)
                {
                    if (union_set(parent, currentHash, neighborHash))
                        islands--;
                }
            }
        }
        ans.push_back(islands);
    }
    return ans;
}