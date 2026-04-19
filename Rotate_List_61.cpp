//
// Created by Anh Le on 4/10/26.
//

#include "ListNode.h"

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr)
        return head;
    int size = 1;
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        size++;
    }
    k %= size;
    if (k == 0)
        return head;
    ListNode* prevHead = head;
    for (int i = 1; i < size - k; i++)
        prevHead = prevHead->next;

    tail->next = head;
    head = prevHead->next;
    prevHead->next = nullptr;
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* arr[505];
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *current = dummy;
    int size = 0;
    while (current != nullptr)
    {
        arr[size++] = current;
        current = current->next;
    }
    size--;
    k %= size;
    if (k == 0) return head;
    int newHeadIndex = size - k +1;
    dummy->next = arr[newHeadIndex];
    arr[newHeadIndex-1]->next = nullptr;
    arr[size]->next = head;
    return dummy->next;
}



