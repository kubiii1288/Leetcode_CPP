//
// Created by Anh Le on 10/21/25.
//
bool isHappy(int n) {
    if (n == 1) return true;
    unordered_set<int> set;
    while (n!= 1)
    {
        int sum = 0;
        while ( n > 0)
        {
            int last_digit = n % 10;
            sum += (last_digit * last_digit);
            n /= 10;
        }
        n = sum;
        if (set.find(sum) == set.end())
        {
            set.insert(sum);
        } else
        {
            break;
        }
    }
    return n == 1;
}