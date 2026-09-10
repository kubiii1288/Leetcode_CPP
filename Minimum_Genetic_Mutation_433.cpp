int minMutation(string startGene, string endGene, vector<string>& bank)
{
    if (startGene == endGene)
        return 0;
    char validChars[4] = {'A', 'C', 'G', 'T'};
    unordered_set<string> wordBank(bank.begin(), bank.end());
    if (wordBank.find(endGene) == wordBank.end()) return -1;
    queue<string> q;
    q.push(startGene);
    int ans = 0;
    while (!q.empty())
    {
        int currentSize = q.size();
        for (int i = 1; i <= currentSize; i++)
        {
            string currentGene = q.front();
            if (currentGene == endGene)
                return ans;
            q.pop();
            for (int j = 0; j <= 7; j++)
            {
                char current_char = currentGene[j];
                for (char c : validChars)
                {
                    if (c != current_char)
                    {
                        currentGene[j] = c;
                        unordered_set<string>::iterator it = wordBank.find(currentGene);
                        if (it != wordBank.end())
                        {
                            q.push(currentGene);
                            wordBank.erase(it);
                        }
                    }
                }
                // revert to the origin
                currentGene[j] = current_char;
            }
        }
        ans++;
    }
    return -1;
}
