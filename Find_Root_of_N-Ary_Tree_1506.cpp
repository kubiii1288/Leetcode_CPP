//
// Created by Anh Le on 9/9/26.
//
Node* findRoot(vector<Node*> tree) {
    int x = 0;
    for (Node* node : tree)
    {
        x ^= node->val;
        for (Node* child : node->children)
            x ^= child->val;
    }
    for (Node* node : tree)
    {
        if (node->val == x)
            return node;
    }
    return nullptr;
}