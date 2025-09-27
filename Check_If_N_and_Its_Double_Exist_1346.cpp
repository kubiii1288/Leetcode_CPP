//
// Created by Anh Le on 3/15/25.
//


bool checkIfExist(vector<int>& arr)
{
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        map.insert({arr[i], i});
    }
    for (int i = 0; i < arr.size(); i++)
    {
        unordered_map<int, int>::iterator it = map.find(arr.at(i) * 2);
        if (it != map.end() && it->second != i)
        {
            return true;
        }
    }

    return false;
}
