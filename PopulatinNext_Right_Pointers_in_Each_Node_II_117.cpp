Node* connect(Node* root) {
    if (root == nullptr) return nullptr;

    Node* current = root;
    while (current !=nullptr)
    {
        Node dummy = Node(-1);
        Node *tail = &dummy;
        while (current != nullptr)
        {
            if (current->left != nullptr)
            {
                tail->next = current->left;
                tail = tail->next;
            }
            if (current->right != nullptr)
            {
                tail->next = current->right;
                tail = tail->next;
            }
            current = current->next;
        }
        current = dummy.next;
    }
    return root;
}