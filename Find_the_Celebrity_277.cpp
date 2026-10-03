//
// Created by Anh Le on 9/10/26.
//
int findCelebrity(int n) {
    int a = 0, b = n-1;
    while (a !=b)
    {
        if (knows(a,b))
        {
            a++;
        } else b--;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == a) continue;
        if (!knows(i,a) || knows(a,i))
            return -1;
    }

    return a;
}