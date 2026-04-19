//
// Created by Anh Le on 4/7/26.
//
ListNode* solve(ListNode* head, ListNode** latestHead) {
    if (head == nullptr || head->next == nullptr) {
        *latestHead = head;
        return head;
    }
    ListNode* tail = solve(head->next, latestHead);
    tail->next = head;
    head->next = nullptr;
    return head;
}
ListNode* reverseList(ListNode* head) {
    ListNode* latestHead = nullptr;
    solve(head, &latestHead);
    return latestHead;
}

ListNode* reverseList_optimal_recursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}