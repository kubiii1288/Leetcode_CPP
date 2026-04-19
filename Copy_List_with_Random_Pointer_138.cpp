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
    if (head == nullptr)
        return nullptr;
    unordered_map<Node*, Node*> map;
    Node* mainPointer = head;
    Node* clonePointer = new Node(head->val);
    map[mainPointer] = clonePointer;
    while (mainPointer->next != nullptr) {
        mainPointer = mainPointer->next;
        clonePointer->next = new Node(mainPointer->val);
        clonePointer = clonePointer->next;
        map[mainPointer] = clonePointer;
    }

    mainPointer = head;
    clonePointer = map[mainPointer];
    clonePointer->random = map[mainPointer->random];
    while (mainPointer->next != nullptr) {
        mainPointer = mainPointer->next;
        clonePointer = map[mainPointer];
        clonePointer->random = map[mainPointer->random];
    }
    return map[head];
}