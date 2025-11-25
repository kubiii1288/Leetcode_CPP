//
// Created by Anh Le on 10/18/25.
//
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int cnt = 0;
        for (int& num : nums) {
            if (num & 1)
                cnt++;
            num >>= 1;
        }
        if (cnt % 3)
            ans += (1 << i);
    }
    return ans;
}