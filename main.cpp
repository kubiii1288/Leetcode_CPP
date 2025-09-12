#include <iostream>
#include <set>
using namespace std;

string reverseVowels(string s) {
     string vowels = "aeiouAEIOU";
    int i = 0, j = s.size()-1;
    while (i < j)
    {
        while (i < j && (vowels.find(s[i]) == -1))
        {
            i++;
        }

        while (i < j && (vowels.find(s[j]) == -1))
        {
            j--;
        }
        swap(s[i], s[j]);
        i++; j--;
    }
    return s;
}

int main()
{
    cout << reverseVowels("leetcode") << endl;
    return 0;
}
