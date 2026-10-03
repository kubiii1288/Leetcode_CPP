//
// Created by Anh Le on 9/22/26.
//
class ZigzagIterator
{
public:
    vector<int> &arr1, &arr2;
    int i = 0, j = 0;
    bool turnArr1 = true;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) : arr1(v1), arr2(v2) {}
    int next()
    {
        if (i < arr1.size() && j < arr2.size())
        {
            if (turnArr1)
            {
                turnArr1 = false;
                return arr1[i++];
            }
            else
            {
                turnArr1 = true;
                return arr2[j++];
            }
        }
        if (i < arr1.size())
        {
            return arr1[i++];
        }
        return arr2[j++];
    }

    bool hasNext()
    {
        return i < arr1.size() || j < arr2.size();
    }
};

