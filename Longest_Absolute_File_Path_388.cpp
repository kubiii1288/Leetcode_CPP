vector<int> findSubstring(string& s, vector<string>& words)
{
    const int word_len = words.back().size();
    const int num_words = words.size();
    const int range = num_words * word_len;
    vector<int> ans;
    if (s.size() < range)
        return ans;
    unordered_map<string, int> freqMap;
    for (string& w : words)
        freqMap[w]++;

    for (int offset = 0; offset < word_len; offset++)
    {
        int start = offset;
        int wordUsed = 0;
        unordered_map<string, int> currentFreq;

        for (int end = offset; end + word_len <= s.size();
             end += word_len)
        {
            string w = s.substr(end, word_len);
            if (freqMap.count(w))
            {
                currentFreq[w]++;
                wordUsed++;

                while (currentFreq[w] > freqMap[w])
                {
                    string leftMostWord = s.substr(start, word_len);
                    currentFreq[leftMostWord]--;
                    start += word_len;
                    wordUsed--;
                }
                if (wordUsed == num_words)
                {
                    ans.push_back(start);
                    string leftMostWord = s.substr(start, word_len);
                    currentFreq[leftMostWord]--;
                    start += word_len;
                    wordUsed--;
                }
            }
            else
            {
                currentFreq.clear();
                wordUsed = 0;
                start = end + word_len;
            }
        }
    }

    return ans;
}
