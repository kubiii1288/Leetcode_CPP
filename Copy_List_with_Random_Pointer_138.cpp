//
// Created by Anh Le on 4/4/26.
//
Node* copyRandomList(Node* head) {
    if (head == nullptr)
        return nullptr;
    Node* mainPtr = head;
    Node* clonePtr;

    while (mainPtr != nullptr) {
        clonePtr = new Node(mainPtr->val);
        clonePtr->next = mainPtr->next;
        mainPtr->next = clonePtr;
        mainPtr = clonePtr->next;
    }

    mainPtr = head;
    while (mainPtr != nullptr) {
        mainPtr->next->random =
            mainPtr->random == nullptr ? nullptr : mainPtr->random->next;
        mainPtr = mainPtr->next->next;
    }

    mainPtr = head;
    Node* headClone = head->next;

    while (mainPtr != nullptr) {
        clonePtr = mainPtr->next;
        mainPtr->next = clonePtr->next;
        clonePtr->next = mainPtr->next == nullptr ? nullptr : mainPtr->next->next;
        mainPtr = mainPtr->next;
    }
    return headClone;
}


Node* copyRandomList(Node* head) {
    if (head == nullptr) return head;
    unordered_map<Node*,Node*> mp;
    Node* current = head;
    while (current != nullptr)
    {
        mp[current] = new Node(current->val);
        current = current->next;
    }
    current = head;
    while (current != nullptr)
    {
        mp[current]->next = mp[current->next];
        mp[current]->random = mp[current->random];
        current = current->next;
    }
    return mp[head];
}