//
// Created by Anh Le on 4/5/26.
//

struct pair_hash
{
    size_t operator() (const pair<int,int> &p) const
    {
        return hash<long long>()(
             (long long) p.first << 32 | (unsigned int) p.second
        );
    }
};

inline int get_gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
pair<int,int> get_slope(const int x1, const int y1, const int x2, const int y2)
{
    int dy = (y2 - y1);
    int dx = (x2 - x1);
    if (dx == 0 )
        return {1,0};
    if (dy == 0)
        return {0,1};
    int gcd = get_gcd(dy,dx);
    dy /= gcd;
    dx /= gcd;
    if (dx < 0)
    {
        dy = -dy;
        dx = -dx;
    }
    return {dy,dx};
}
int maxPoints(vector<vector<int>>& points) {
    if (points.size() <= 2) return points.size();
    int ans = -1;
    const int N = points.size();
    for (int i = 0; i < N; i++)
    {
        unordered_map<pair<int,int>,int, pair_hash> mp;
        int x1 = points[i][0];
        int y1 = points[i][1];
        int local_ans = -1;
        for (int j = i + 1; j < N; j++)
        {
            int x2 = points[j][0];
            int y2 = points[j][1];
            pair<int,int> slope = get_slope(x1,y1,x2,y2);
            mp[slope]++;
            local_ans = max(local_ans, mp[slope]);
        }
        ans = max(ans, local_ans+1);
    }
    return ans;
}