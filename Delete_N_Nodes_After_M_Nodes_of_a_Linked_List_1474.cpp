//
// Created by Anh Le on 9/2/26.
//
ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode* current = head;
    while (true) {
        for (int i = 1; i < m && current; i++)
            current = current->next;
        if (current == nullptr)
            break;
        ListNode* next = current->next;
        for (int i = 0; i < n && next; i++) {
            ListNode* temp = next;
            next = next->next;
            delete temp;
        }
        current->next = next;
        current = next;
    }
    return head;
}