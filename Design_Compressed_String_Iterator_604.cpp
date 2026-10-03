//
// Created by Anh Le on 9/24/26.
//

class StringIterator {
public:
    string s;
    int index = 0;
    int len = 0;
    char c;
    StringIterator(string compressedString) : s(std::move(compressedString)) {}

    char next() {
        if (!hasNext()) return ' ';
        if (len == 0) {
            c = s[index++];
            for (; index < s.size() && isdigit(s[index]); index++)
            {
                len = len * 10 + (s[index] - '0');
            }
        }
        len--;
        return c;
    }

    bool hasNext() { return len > 0 || index < s.size(); }
};
