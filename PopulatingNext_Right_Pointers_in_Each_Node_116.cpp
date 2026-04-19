//
// Created by Anh Le on 4/15/26.
//

Node* connect(Node* root) {
    if (root == nullptr) return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node* front = q.front();
            q.pop();
            if (i < size -1)
                front->next = q.front();
            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
    }
    return root;
}

Node* connect(Node* root) {
    if (root == nullptr)
        return nullptr;
    Node* leftMost = root;

    while (leftMost->left != nullptr) {
        Node* current = leftMost;
        while (current != nullptr) {
            current->left->next = current->right;
            if (current->next != nullptr)
                current->right->next = current->next->left;
            current = current->next;
        }
        leftMost = leftMost->left;
    }
    return root;
}