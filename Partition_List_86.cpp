//
// Created by Anh Le on 4/10/26.
//
ListNode* partition(ListNode* head, int x) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode dummyLess =  ListNode(INT_MAX);
    ListNode dummyGreater = ListNode(INT_MIN);
    ListNode* less = &dummyLess;
    ListNode* greater = &dummyGreater;

    ListNode* current = head;
    while (current != nullptr)
    {
        if (current->val < x)
        {
            less->next = current;
            less = less->next;
        } else
        {
            greater->next = current;
            greater = greater->next;
        }
        current = current->next;
    }
    less->next = dummyGreater.next;
    greater->next = nullptr;
    return dummyLess.next;
}