int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    if (beginWord == endWord) return 0;
    unordered_set<string> wordBank(wordList.begin(), wordList.end());
    if (wordBank.find(endWord) == wordBank.end()) return 0;
    string alphabet;
    alphabet.reserve('z' - 'a');
    for (char i = 'a'; i <= 'z'; i++) alphabet.push_back(i);
    queue<string> q;
    q.push(beginWord);
    int sequenceLength = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size-- > 0)
        {
            string currentWord = q.front();
            q.pop();
            if (currentWord == endWord) return sequenceLength;
            for (int i = 0; i < currentWord.size(); i++)
            {
                char originChar = currentWord[i];
                for (char c : alphabet)
                {
                    if (c != originChar)
                    {
                        currentWord[i] = c;
                        unordered_set<string>::iterator it = wordBank.find(currentWord);
                        if (it != wordBank.end())
                        {
                            // q.push(it->data());
                            q.push(currentWord);
                            wordBank.erase(it);
                        }
                    }
                }
                currentWord[i] = originChar;
            }
        }
        sequenceLength++;
    }
    return 0;
}
