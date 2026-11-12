//
// Created by kubiii on 10/23/26.
//

Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* first = p;
    Node* second = q;
    while (first != second) {
        first = first ? first->parent : q;
        second = second ? second->parent : p;
    }
    return first;
}