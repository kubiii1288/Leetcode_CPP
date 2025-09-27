//
// Created by Anh Le on 9/21/25.
//
void add_spaces(string& s, int nums)
{
    while (nums-- > 0)
        s.push_back(' ');
}

string mid_align(vector<string>& s, int maxWidth, int words_size)
{
    int spaces = maxWidth - words_size;
    int spaces_mid = spaces / (s.size() - 1);
    int remainder_space = spaces % (s.size() - 1);
    string line;
    for (int i = 0; i < s.size() - 1; i++)
    {
        line += s[i];
        add_spaces(line, spaces_mid);
        if (remainder_space > 0)
            add_spaces(line, 1);
        remainder_space--;
    }
    line += s.back();
    return line;
}

string left_align(vector<string>& s, int maxWidth, int words_size)
{
    int spaces = maxWidth - words_size;
    string line;
    for (int i = 0; i < s.size(); i++)
    {
        line.append(s[i]);
        if (spaces > 0)
            line.push_back(' ');
        spaces--;
    }
    add_spaces(line, spaces);

    return line;
}

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> ans;
    int index = 0;
    while (index < words.size())
    {
        int current_size = 0;
        vector<string> line;
        while (index < words.size() &&
            (line.size() + current_size + words[index].size() <=
                maxWidth))
        {
            line.push_back(words[index]);
            current_size += words[index].size();
            index++;
        }
        if (index == words.size())
        {
            ans.push_back(left_align(line, maxWidth, current_size));
        }
        else
        {
            if (line.size() == 1)
                ans.push_back(left_align(line, maxWidth, current_size));
            else
                ans.push_back(mid_align(line, maxWidth, current_size));
        }
    }
    return ans;
}
