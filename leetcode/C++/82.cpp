#include "listnode.h"
#include <vector>
using namespace std;
class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head;
        ListNode *pre = head;
        while (p != nullptr)
        {
            ListNode *p1 = p->next;
            while (p1 != nullptr && p1->val == p->val)
            {
                p1 = p1->next;
            }
            if (p1 != p->next)
            {
                if (p == head)
                    head = p1;
                pre->next = p1;
            }
            else
            {
                pre = p;
            }
            p = p1;
        }
        return head;
    }
};