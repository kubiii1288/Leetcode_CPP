
int getDistance(int x, int y, int a, int b)
{
    return abs(x-a) + abs(y-b);
}
vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
    int W = workers.size();
    for (int i = 0; i < W; i++)
    {
        int x = workers[i][0];
        int y = workers[i][1];
        for (int j = 0; j < bikes.size(); j++)
        {
            int a = bikes[j][0];
            int b = bikes[j][1];
            q.push({getDistance(x,y,a,b), i, j});
        }
    }

    vector<int> ans(W,-1);
    vector<bool> bikeAssign(bikes.size(),false);
    while (!q.empty())
    {
        auto [dist,wID,bID] = q.top();
        q.pop();
        if (ans[wID] == -1 && !bikeAssign[bID])
        {
            ans[wID] = bID;
            bikeAssign[bID] = true;
            W--;
        }
        if (W==0) break;
    }
    return ans;
}