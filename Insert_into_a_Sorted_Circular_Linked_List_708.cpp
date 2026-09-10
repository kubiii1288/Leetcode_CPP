//
// Created by Anh Le on 9/2/26.
//
Node* insert(Node* head, int insertVal) {
    if (head == nullptr) {
        head = new Node(insertVal);
        head->next = head;
        return head;
    }
    Node* current = head;
    Node* next = current->next;
    while (true) {
        bool atRightPos =
            (current->val <= insertVal && insertVal <= next->val);
        bool atTail =
            (current->val > next->val &&
             (current->val <= insertVal || insertVal <= next->val));
        bool atFullLoop = (current->next == head);
        if (atRightPos || atTail || atFullLoop) {
            Node* newNode = new Node(insertVal);
            newNode->next = next;
            current->next = newNode;
            break;
        }
        current = next;
        next = next->next;
    }
    return head;
}