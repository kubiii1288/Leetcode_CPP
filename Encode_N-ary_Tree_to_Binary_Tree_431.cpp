//
// Created by Anh Le on 9/21/26.
//
// Encodes an n-ary tree to a binary tree.
TreeNode* encode(Node* root) {
    if (root == nullptr) return nullptr;
    TreeNode* binTreeRoot = new TreeNode(root->val);
    if (root->children.empty()) return binTreeRoot;
    binTreeRoot->left = encode(root->children.front());
    TreeNode* current = binTreeRoot->left;
    for (int i = 1; i < root->children.size(); i++)
    {
        current->right = encode(root->children[i]);
        current = current->right;
    }
    return binTreeRoot;
}

// Decodes your binary tree to an n-ary tree.
Node* decode(TreeNode* root) {
    if (root == nullptr) return nullptr;
    Node* nTreeRoot = new Node(root->val);
    TreeNode* current = root->left;
    while (current)
    {
        nTreeRoot->children.push_back(decode(current));
        current = current->right;
    }
    return nTreeRoot;
}