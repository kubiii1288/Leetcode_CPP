//
// Created by Anh Le on 8/10/26.
//
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* firstEven = even;
    while (even && even->next)
    {
        odd->next = even->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = firstEven;

    return head;
}