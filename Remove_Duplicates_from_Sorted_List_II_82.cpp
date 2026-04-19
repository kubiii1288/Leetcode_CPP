//
// Created by Anh Le on 12/22/25.
//
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    ListNode *ans = nullptr,*current = nullptr;
    ListNode *first, *second;
    first = head;
    second = head->next;
    int latest_duplicated = -10000;
    while (second != nullptr)
    {
        while (second != nullptr && first->val == second->val)
        {
            first = first->next;
            second = second->next;
            latest_duplicated = first->val;
        }

        if (first->val != latest_duplicated)
        {
            if (ans == nullptr)
            {
                ans = new ListNode(first->val);
                current = ans;
            } else
            {
                current->next = new ListNode(first->val);
                current = current->next;
            }
        }
        first = first->next;
        if (second !=nullptr) second = second->next;
    }
    if ( first != nullptr && first->val != latest_duplicated)
    {
        if (ans == nullptr)
            ans = new ListNode(first->val);
        else
            current->next = new ListNode(first->val);
    }
    return ans;
}