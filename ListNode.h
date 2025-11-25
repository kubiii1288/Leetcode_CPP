//
// Created by Anh Le on 11/3/25.
//

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif //LEETCODE_LISTNODE_H