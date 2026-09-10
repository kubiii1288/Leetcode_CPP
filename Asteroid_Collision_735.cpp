//
// Created by Anh Le on 8/9/26.
//
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    ans.reserve(asteroids.size());
    for (int current : asteroids)
    {

        if (current > 0)
        {
            ans.push_back(current);
        } else
        {
            if (ans.empty())
            {
                ans.push_back(current);
            } else
            {
                while (ans.size() && ans.back() >0 && abs(current) > ans.back())
                    ans.pop_back();

                if (ans.empty() || ans.back() < 0)
                    ans.push_back(current);
                else if (ans.back() == abs(current))
                    ans.pop_back();
            }
        }
    }
    return ans;
}

