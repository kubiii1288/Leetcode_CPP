//
// Created by Anh Le on 7/2/26.
//
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int h = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int w = i - left -1;
            ans = max(ans, h * w);
        }
        st.push(i);
    }
    return ans;
}