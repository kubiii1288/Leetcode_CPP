ListNode* reverseKGroup(ListNode* head, int k) {
    if (head->next == nullptr || k == 1) return head;
    vector<ListNode*> arr;
    int size = 0;
    ListNode dummy = ListNode(-1);
    dummy.next = head;
    for (ListNode* iterator = &dummy; iterator != nullptr; iterator = iterator->next)
    {
        arr.push_back(iterator);
    }
    size = arr.size();
    ListNode* preTail = &dummy;
    for (int i = 1; i + k-1 < size; i+=k)
    {
        arr[i]->next = arr[i+k-1]->next;
        for (int curr = i+1; curr < i+k; curr++)
        {
            arr[curr]->next = arr[curr-1];
        }
        preTail->next = arr[i+k-1];
        preTail = arr[i];
    }
    return dummy.next;
}
ListNode* reverseKGroup(ListNode* head, int k)
{
    if (head == nullptr || k == 1) return head;
    ListNode dummy = ListNode(-1);
    dummy.next = head;
    ListNode* preTail = &dummy;
    ListNode* first = preTail->next;
    while (true)
    {
        ListNode* last = preTail;
        for (int countNode = 0; countNode < k && last != nullptr; countNode++)
            last = last->next;

        if (last == nullptr) break;

        ListNode* upperBound = last->next;
        ListNode* prev = first;
        for (ListNode* iter = first->next; iter != upperBound;)
        {
            ListNode* temp = iter->next;
            iter->next = prev;
            prev = iter;
            iter = temp;
        }
        first->next = upperBound;
        preTail->next = last;
        preTail = first;
        first = upperBound;
    }
    return dummy.next;
}
