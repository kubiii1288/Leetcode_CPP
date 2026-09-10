//
// Created by Anh Le on 6/8/26.
//
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* current = head;
    while (current && current->next) {
        swap(current->val, current->next->val);
        current = current->next->next;
    }
    return head;
}