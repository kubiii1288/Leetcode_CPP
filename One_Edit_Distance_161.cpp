//
// Created by Anh Le on 8/25/26.
//
bool isOneEditDistance(string s, string t) {
    const int M = s.size();
    const int N = t.size();

    if (M > N)
        return isOneEditDistance(t, s);
    if (N - M > 1)
        return false;

    for (int i = 0; i < M; i++) {
        if (s[i] != t[i]) {
            if (M == N)
                return s.substr(i + 1) == t.substr(i + 1);

            return s.substr(i) == t.substr(i + 1);
        }
    }
    return M +1 == N;
}