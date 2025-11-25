//
// Created by Anh Le on 11/1/25.
//

#include "TreeNode.h"
#include <iostream>
using namespace std;
TreeNode* createTree(vector<int>& nums, int start, int end)
{
    if (end - start == 0)
    {
        return new TreeNode(nums[start]);
    }
    if (end - start == 1)
    {
        TreeNode* root = new TreeNode(nums[start]);
        root->right = new TreeNode(nums[end]);
        return root;
    }
    int mid = (start + end) /2;
    TreeNode* root = new TreeNode(nums[mid]);
    TreeNode* left = createTree(nums, start, mid-1);
    TreeNode* right = createTree(nums, mid+1, end);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return createTree(nums,0, nums.size()-1);
}