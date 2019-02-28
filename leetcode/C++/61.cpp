#include "listnode.h"
class Solution
{
  public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        ListNode *p = head;
        ListNode *last = nullptr;
        ListNode *res = nullptr;
        int len = 0;
        while (p != nullptr)
        {
            if (p->next == nullptr)
                last = p;
            p = p->next;
            ++len;
        }
        int mod = k >= len ? (k % len) : k;
        mod = len - mod;
        int count = 1;
        last->next = head;
        p = head;
        while (count != mod)
        {
            p = p->next;
            ++count;
        }
        res = p->next;
        p->next = nullptr;
        return res;
    }
};