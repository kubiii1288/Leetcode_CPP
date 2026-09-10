//
// Created by Anh Le on 9/20/25.
//

int trap(vector<int>& height)
{
    int maxL[height.size()];
    int maxR[height.size()];
    int mL = -1;
    int mR = -1;
    int size = height.size();
    maxL[0] = maxR[height.size() - 1] = 0;
    for (int i = 1; i < size; i++)
    {
        mL = std::max(mL, height[i - 1]);
        mR = std::max(mR, height[size - i]);
        maxL[i] = mL;
        maxR[size - i - 1] = mR;
    }
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        int local_max = min(maxL[i], maxR[i]);
        int capacity = local_max - height[i];
        ans += (capacity > 0 ? capacity : 0);
    }
    return ans;
}


int trap_2(vector<int>& height) {
    int l = 0;
    int r = height.size()-1;
    int leftMax = 0;
    int rightMax = 0;
    int ans = 0;

    while (l < r)
    {
        if (height[l] < height[r])
        {
            if (height[l] > leftMax)
                leftMax = height[l];
            else ans += leftMax - height[l];
            l++;
        } else
        {
            if (height[r] > rightMax)
                rightMax = height[r];
            else ans += rightMax - height[r];
            r--;
        }
    }
    return ans;
}