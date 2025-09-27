//
// Created by Anh Le on 9/22/25.
//
class RandomizedSet
{
private:
    unordered_map<int, int> set;
    vector<int> values;

public:
    RandomizedSet() { srand(time(NULL)); }

    bool insert(int val)
    {
        if (set.find(val) == set.end())
        {
            set.insert({val, values.size()});
            values.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (set.find(val) == set.end())
            return false;
        int index = set[val];
        set[values.back()] = index;
        values[index] = values.back();
        values.pop_back();
        set.erase(val);
        return true;
    }

    int getRandom() const { return values[rand() % values.size()]; }
};
