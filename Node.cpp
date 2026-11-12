//
// Created by Anh Le on 11/13/25.
//
#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* parent;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
    }
};