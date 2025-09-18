#include <iostream>
#include <sstream>
using namespace std;

bool both_are_space(char l, char r)
{
    return (l == r) && (r == ' ');
}
string reverseWords(string &s) {
    // trim left
    int left = 0;
    while (s[left] == ' ')
        left++;
    s.erase(0, left);
    // trim right
    int right = s.size() -1;
    while (s[right] == ' ')
        right--;
    s.erase(right+1, s.size());
    int space_index = 0;
    string::iterator new_end = std::unique(s.begin(), s.end(), both_are_space);
    s.erase(new_end, s.end());
    reverse(s.begin(), s.end());
    left = right = 0;
    // for (int i = 0; i <s.size(); i++)
    // {
    //     cout << s[i] <<": " << i << endl;
    // }
    while (left < s.size() && right < s.size())
    {
        // cout << "left: " << left;
        while (right < s.size() && s[right] != ' ')
            right++;
        // cout <<  '-' << "right: " << right << endl;
        reverse(s.begin() + left, s.begin() + right);
        right++;
        left = right;
    }
    return s;
}


int main()
{
    string test = "   I  love  you   ";
    reverseWords(test);
    cout << test << endl;
    return 0;
}
