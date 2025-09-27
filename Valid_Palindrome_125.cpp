//
// Created by Anh Le on 9/17/25.
//

bool isPalindrome(string& s)
{
    string temp;

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
        {
            if (isupper(s[i]))
            {
                temp.push_back(tolower(s[i]));
            }
            else
                temp.push_back(s[i]);
        }
    }

    int head = 0;
    int tail = temp.size() - 1;

    while (head <= tail)
    {
        if (temp[head] != temp[tail])
        {
            return false;
        }
        head++;
        tail--;
    }
    return true;
}
