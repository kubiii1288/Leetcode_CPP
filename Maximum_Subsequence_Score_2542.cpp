//
// Created by Anh Le on 8/13/26.
//

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int,int>> arr;
    for (int i = 0; i < nums1.size();i++)
    {
        arr.push_back({nums2[i],nums1[i]});
    }
    sort(arr.begin(), arr.end(), greater<pair<int,int>>());
    priority_queue<int,vector<int>, greater<int>> heap;
    long long sum = 0;
    long long ans = 0;
    for (auto& [n2,n1] : arr)
    {
        sum += n1;
        heap.push(n1);

        if (heap.size() > k)
        {
            sum -= heap.top();
            heap.pop();
        }
        if (heap.size() == k)
            ans = max(ans, sum * n2);
    }
    return ans;
}