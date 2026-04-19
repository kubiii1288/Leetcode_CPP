//
// Created by Anh Le on 12/23/25.
//
#include <iostream>
using namespace std;
#ifndef LEETCODE_LC_UTILS_H
#define LEETCODE_LC_UTILS_H

ListNode* createLinkedList(vector<int> &v)
{
    ListNode dummy = ListNode(-1);
    ListNode* current = &dummy;
    for (int i : v)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    return dummy.next;
}

void print_Linked_List(ListNode* root)
{
    while (root)
    {
        cout << root->val << ' ';
        root = root->next;
    }
    cout << endl;
}

void freeNode(ListNode *root)
{
    if (root == nullptr) return;
    freeNode(root->next);
    delete root;
}
#endif //LEETCODE_LC_UTILS_H
