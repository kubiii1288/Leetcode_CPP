//
// Created by Anh Le on 12/20/25.
//

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size()+nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),ans.begin());
    int half = ans.size()/2;
    cout << ans.size() << endl;
    if (ans.size() % 2)
    {
        return ans[half];
    }
    return (ans[half] * 1.0 + ans[half-1] * 1.0) /2;
}