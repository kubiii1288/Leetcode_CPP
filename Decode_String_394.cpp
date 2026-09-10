//
// Created by Anh Le on 6/29/26.
//

string decodeString(string s) {
    stack<pair<string,int>> st;
    int num = 0;
    string current = "";
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i];
        if (isdigit(c))
        {
            num = num * 10 + c - '0';
        } else if (c == '[')
        {
            st.push({current, num});
            current = "";
            num = 0;
        } else if (c == ']')
        {
            string prev = st.top().first;
            int repeat = st.top().second;
            st.pop();
            while (repeat--)
                prev.append(current);
            current = prev;
        } else
        {
            current.push_back(s[i]);
        }
    }

    return current;
}