#include <iostream>

using namespace std;

int main()
{
    vector<int> v = {0,1,2,2,3,0,4,2};
    v.erase(std::remove(v.begin(), v.end(), 2), v.end());
    for (const int i : v)
    {
        cout << i <<" ";
    }
    return 0;
}
