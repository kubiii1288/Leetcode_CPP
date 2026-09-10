//
// Created by Anh Le on 8/9/26.
//


ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode* temp = head;
    int index = 0;
    unordered_map<int,ListNode*> mp;
    while (temp != nullptr)
    {
        mp[index++] = temp;
        temp = temp->next;
    }
    int mid = mp.size()/2;
    mp[mid-1]->next = mp[mid]->next;
    return head;
}

ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode* fast = head->next->next;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}
