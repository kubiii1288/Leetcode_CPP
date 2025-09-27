//
// Created by Anh Le on 3/11/25.
//

using namespace std;

int numberOfSteps(int num)
{
    int step = 0;
    while (num != 0)
    {
        if (num & 1)
            num--;
        else num /= 2;

        step++;
    }
    return step;
}
