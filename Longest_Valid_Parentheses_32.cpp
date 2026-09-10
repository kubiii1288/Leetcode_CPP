//
// Created by Anh Le on 5/22/26.
//
int longestValidParentheses(string &s) {
    vector<int> st;
    st.reserve(s.size()+1);
    st.push_back(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push_back(i);
        } else
        {
            st.pop_back();
            if (st.empty())
            {
                st.push_back(i);
            } else
            {
                ans = max(ans, i - st.back());
            }
        }
    }
    return ans;
}