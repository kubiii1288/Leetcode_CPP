//
// Created by Anh Le on 10/17/25.
//
int to_int(char c)
{
    return c-'0';
}
char to_char(int i)
{
    return '0' + i;
}
string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans;
    int max_len = max(a.size(), b.size());
    int first, second, carry = 0, digit= 0;
    for (int i = 0; i < max_len; i++)
    {
        first = (i < a.size()) ? to_int(a[i]) : 0;
        second = (i < b.size()) ? to_int(b[i]) : 0;

        digit = (first + second + carry) % 2;
        carry = (first + second + carry ) / 2;
        ans.push_back(to_char(digit));
    }
    if (carry) ans.push_back(to_char(carry));
    reverse(ans.begin(), ans.end());
    return ans;
}