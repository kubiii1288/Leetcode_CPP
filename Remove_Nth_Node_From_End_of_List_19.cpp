//
// Created by Anh Le on 4/10/26.
//
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr)
        return nullptr;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    vector<ListNode*> arr(32, nullptr);
    ListNode* current = dummy;
    int size = 0;
    while (current != nullptr) {
        arr[size] = current;
        size++;
        current = current->next;
    }

    int target = size - n;
    arr[target - 1]->next = arr[target + 1];

    return dummy->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr)
        return nullptr;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* cur = head;
    while (n-- > 1)
        cur = cur->next;
    while (cur->next != nullptr) {
        prev = prev->next;
        cur = cur->next;
    }
    prev->next = prev->next->next;

    return dummy->next;
}