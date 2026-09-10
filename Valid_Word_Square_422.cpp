//
// Created by Anh Le on 8/29/26.
//
bool validWordSquare(vector<string>& words) {
    for (int column = 0; column < words.size(); column++)
    {
        string vWord;
        for (int row = 0; row < words.size() && column < words[row].size(); row++)
            vWord.push_back(words[row][column]);
        if (vWord != words[column])
            return false;
    }
    return true;
}