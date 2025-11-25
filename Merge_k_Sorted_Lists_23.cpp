//
// Created by Anh Le on 11/10/25.
//
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    if (list1->val < list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }
    tail = head;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1 == nullptr)
        tail->next = list2;
    if (list2 == nullptr)
        tail->next = list1;
    return head;
}

ListNode* merge_sorted_lists(vector<ListNode*>& list, const int left,
                             const int right) {
    if (left == right)
        return list[left];
    if (right - left == 1)
        return mergeTwoLists(list[left], list[right]);
    const int mid = (left + right) / 2;
    ListNode* left_part = merge_sorted_lists(list, left, mid);
    ListNode* right_part = merge_sorted_lists(list, mid + 1, right);
    return mergeTwoLists(left_part, right_part);
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty())
        return nullptr;
    return merge_sorted_lists(lists, 0, lists.size() - 1);
}