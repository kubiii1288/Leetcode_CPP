//
// Created by Anh Le on 9/4/26.
//
ListNode* reverse(ListNode* head) {
    if (head == nullptr)
        return head;
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}
ListNode* plusOne(ListNode* head) {
    head = reverse(head);
    ListNode dummy(-1, head);
    ListNode* current = &dummy;
    ListNode* next = dummy.next;

    int carry = 1;
    while (carry) {
        if (next == nullptr) {
            current->next = new ListNode(0);
            next = current->next;
        }
        int sum = (next->val + carry);
        carry = (sum /10);
        next->val = sum % 10;
        current = next;
        next = current->next;
    }
    return reverse(head);
}