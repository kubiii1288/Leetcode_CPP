//
// Created by Anh Le on 9/1/26.
//

class FirstUnique {
public:
    unordered_map<int,int> mp;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for (int i : nums)
        {
            mp[i]++;
            if (mp[i] == 1)
                q.push(i);
        }
    }

    int showFirstUnique() {
        while (!q.empty() && mp[q.front()] != 1)
            q.pop();
        if (q.empty()) return -1;
        return q.front();
    }

    void add(int value) {
        mp[value]++;
        if (mp[value] == 1)
            q.push(value);
    }
};
