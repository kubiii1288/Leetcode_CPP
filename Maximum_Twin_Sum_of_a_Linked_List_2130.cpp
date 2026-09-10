

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

int pairSum(ListNode* head) {
    int ans = 0;
    ListNode* fast = head->next;
    ListNode* slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = reverseList(slow->next);
    slow->next = nullptr;
    while (head != nullptr)
    {
        ans = max(ans, head->val + newHead->val);
        head = head->next;
        newHead = newHead ->next;
    }
    return ans;
}