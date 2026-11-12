//
// Created by kubiii on 10/24/26.
//
long long maximumBooks(vector<int>& books) {
    const int n = books.size();
    long long ans = 0;
    vector<long long> dp(n,0);
    // store bottleneck indices
    stack<int> st;
    for (int i = 0; i < n; i++) {
        // remove shelf that not a bottleneck
        while (!st.empty() && books[st.top()] - st.top() >= books[i]-i) {
            st.pop();
        }

        // nearest bottleneck
        int j = (st.empty() ? -1 : st.top());
        int len = min(i-j, books[i]);
        int first = books[i] - len +1;
        int last = books[i];
        long long sum = 1LL* len * (first + last) /2;

        dp[i] = (j == -1 ? sum : (sum + dp[j]));
        ans = max(ans,dp[i]);
        st.push(i);
    }
    return ans;
}
