//
// Created by Anh Le on 4/5/26.
//
int longestPalindromeSubseq(string& s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    const int N = s.size();
    int *prev = new int[N+1];
    int *cur = new int[N+1];
    memset(prev,0,sizeof(int) * (N+1));
    memset(cur,0,sizeof(int) * (N+1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (s[i-1] == rev_s[j-1])
                cur[j] = prev[j-1]+1;
            else cur[j] = max(prev[j], cur[j-1]);
        }
        swap(prev,cur);
    }
    delete[] prev;
    delete[] cur;
    return prev[N];
}