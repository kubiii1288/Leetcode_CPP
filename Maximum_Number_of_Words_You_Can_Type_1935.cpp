//
// Created by Anh Le on 9/15/25.
//

int canBeTypedWords(string& text, string& brokenLetters)
{
    stringstream ss(text);
    string word;
    int ans = 0;
    while (ss >> word)
    {
        bool found = false;
        for (int i = 0; i < brokenLetters.size() && !found; i++)
        {
            found = (word.find(brokenLetters[i]) != string::npos);
        }
        if (!found)
            ans++;
    }
    return ans;
}
