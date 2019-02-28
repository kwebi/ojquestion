#include "listnode.h"
class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head;
        int len = 0;
        while (p != nullptr)
        {
            p = p->next;
            ++len;
        }
        if (n == len)
        {
            head = head->next;
            return head;
        }
        p = head;
        int count = 1;
        ListNode *t = nullptr;
        while (p != nullptr)
        {
            if (len - n == count)
            {
                t = p;
                break;
            }
            ++count;
            p = p->next;
        }
        ListNode *tmp = t->next;
        t->next = tmp->next;
        delete tmp;
        return head;
    }
};