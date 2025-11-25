//
// Created by Anh Le on 11/3/25.
//
ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    // search middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* right = slow->next;
    slow->next = nullptr;
    ListNode* left = head;
    right = sortList(right);
    left = sortList(left);

    ListNode* final_head = nullptr;

    if (right->val < left->val) {
        final_head = right;
        right = right->next;
    } else {
        final_head = left;
        left = left->next;
    }
    ListNode* pointer = final_head;
    while (right != nullptr && left != nullptr) {
        if (right->val < left->val) {
            pointer->next = right;
            right = right->next;
        } else {
            pointer->next = left;
            left = left->next;
        }
        pointer = pointer->next;
    }
    if (right == nullptr) {
        pointer->next = left;
    } else {
        pointer->next = right;
    }
    return final_head;
}