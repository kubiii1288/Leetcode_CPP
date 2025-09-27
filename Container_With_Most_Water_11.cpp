//
// Created by Anh Le on 9/26/25.
//

int maxArea(vector<int>& height)
{
    int left = 0;
    int right = height.size() - 1;
    int max_area = -1;
    while (left < right)
    {
        max_area =
            std::max(max_area, (right - left) *
                     std::min(height[left], height[right]));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_area;
}
