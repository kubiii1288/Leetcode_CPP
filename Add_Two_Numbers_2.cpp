//
// Created by Anh Le on 12/8/25.
//
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* current = new ListNode();
    ListNode* ans = current;
    int num1 = 0;
    int num2 = 0;
    int carry = 0;
    while (l1 || l2  || carry )
    {
        num1 = (l1 == nullptr ? 0 : l1->val);
        num2 = (l2 == nullptr ? 0 : l2->val);
        current->val = (num1 + num2 + carry) % 10;
        carry = (num1 + num2 + carry > 9);
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        if (l1 || l2 || carry)
        {
            current->next = new ListNode();
            current = current->next;
        }
    }
    return ans;
}