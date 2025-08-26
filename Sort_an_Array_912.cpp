//
// Created by Anh Le on 3/23/25.
//
#include <iostream>
using namespace std;

// void merge(int *arr, const int left, const int mid, const int right)
// {
//     const int left_size = mid - left + 1;
//     const int right_size = right - mid;
//
//     int temp_left[left_size];
//     int temp_right[right_size];
//
//     for (int i = 0; i < left_size; i++)
//     {
//         temp_left[i] = arr[left + i];
//     }
//     for (int i = 0; i < right_size; i++)
//     {
//         temp_right[i] = arr[mid+ i + 1];
//     }
//     int l = 0, r = 0, k = left;
//     while (l < left_size && r < right_size)
//     {
//         if (temp_left[l] < temp_right[r])
//             arr[k++] = temp_left[l++];
//         else arr[k++] = temp_right[r++];
//     }
//
//     while (l < left_size)
//         arr[k++] = temp_left[l++];
//
//     while (r < right_size)
//         arr[k++] = temp_right[r++];
// }
// void merge_sort_recursion(int* arr, const int left, const int right)
// {
//     if (left >= right) return;
//     int pivot = left + (right - left) / 2;
//     merge_sort_recursion(arr, left, pivot);
//     merge_sort_recursion(arr, pivot + 1, right);
//
//     merge(arr, left, pivot, right);
// }
//
// void merge_sort(int* arr, int length)
// {
//     merge_sort_recursion(arr, 0, length -1);
// }
//
// int* sortArray(int* nums, int numsSize, int* returnSize) {
//     merge_sort(nums, numsSize);
//     return nums;
// }