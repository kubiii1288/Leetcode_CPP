//
// Created by kubiii on 11/6/26.
//
int appendCharacters(string& s, string& t) {
    int index_t = 0;
    for (char c : s) {
        index_t += c == t[index_t];
    }
    return t.size() - index_t;
}
