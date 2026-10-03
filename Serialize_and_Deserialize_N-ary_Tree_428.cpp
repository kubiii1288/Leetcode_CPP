//
// Created by Anh Le on 9/20/26.
//

void encode(Node* node, ostringstream &s)
{
    if (node == nullptr) return;
    s << node->val << ' ';
    s << node->children.size() << ' ';
    for (Node* child : node->children)
        encode(child, s);
}
// Encodes a tree to a single string.
string serialize(Node* root) {
    if (root == nullptr) return "";
    ostringstream ss;
    encode(root,ss);
    return ss.str();
}

Node* decode(istringstream &in)
{
    int value;
    int size;
    if (!(in >> value))
        return nullptr;
    Node* node = new Node(value);
    in >> size;
    for (int i = 0; i < size; i++)
    {
        node->children.push_back(decode(in));
    }
    return node;
}
// Decodes your encoded data to tree.
Node* deserialize(string data) {
    if (data.empty())
        return nullptr;
    istringstream in(data);
    return decode(in);
}