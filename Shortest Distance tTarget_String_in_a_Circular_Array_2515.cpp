int closestTarget(vector<string>& words, string& target, int startIndex) {
    const int size = words.size();
    int ans = size;
    for (int i = 0; i < size; i++) {
        if (words[i] == target) {
            int gap = abs(startIndex - i);
            ans = min(ans, min(gap, size - gap));
        }
    }
    return ans != size ? ans : -1;
}