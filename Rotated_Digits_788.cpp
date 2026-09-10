//
// Created by Anh Le on 5/1/26.
//
bool isValid(int n)
{
    bool canChangeValue = false;
    int d;
    while (n > 0)
    {
        d = n % 10;
        if (d == 3 || d == 4 || d == 7) return false;
        if (d == 2 || d == 5 || d ==6 || d== 9)
            canChangeValue = true;
        n /= 10;
    }
    return canChangeValue;
}
int rotatedDigits(int n) {
    int ans= 0;
    for (int i = 1; i <= n; i++)
        if (isValid(i)) ans++;
    return ans;
}
