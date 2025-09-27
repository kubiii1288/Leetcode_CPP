//
// Created by Anh Le on 3/11/25.
//
struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

ListNode* middleNode(ListNode* head)
{
    ListNode* first = head;
    ListNode* second = head;

    while (second->next != nullptr)
    {
        first = first->next;
        second = second->next;
        if (second->next != nullptr)
        {
            second = second->next;
        }
    }

    return first;
}
