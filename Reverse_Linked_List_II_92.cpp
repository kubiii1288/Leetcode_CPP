//
// Created by Anh Le on 4/7/26.
//
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right)
        return head;
    if (head->next == nullptr)
        return head;
    ListNode* dummyNode = new ListNode(0);
    dummyNode->next = head;

    ListNode* preLeft = dummyNode;
    ListNode* current = dummyNode->next;

    for (int i = 1; i < left; i++) {
        preLeft = current;
        current = current->next;
    }
    ListNode* temp = current->next;
    for (int i = 1; i <= right - left; i++) {
        ListNode* prev = current;
        current = temp;
        temp = temp->next;
        current->next = prev;
    }

    cout << current->val << endl;
    preLeft->next->next = temp;
    preLeft->next = current;
    return dummyNode->next;
}