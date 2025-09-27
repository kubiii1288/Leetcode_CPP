string convert(string& s, int numRows)
{
    if (numRows == 1) return s;
    string ans;
    string matrix[numRows];
    int dir = -1;
    int index = 0;
    int row = 0;
    while (index < s.size())
    {
        matrix[row].push_back(s[index]);
        if (row == 0 || row == numRows - 1)
            dir *= -1;
        row += dir;
        index++;
    }
    for (string& i : matrix)
        ans.append(i);
    return ans;
}
