#include <algorithm>
using namespace std;
#include "listnode.h"
class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        int count = 0;
        while (p1->next != nullptr)
        {
            p1->next = p2->next;
            p2->next = p1;
            if (count == 0)
                head = p2;
            p2 = p1->next;
            if (p2 == nullptr || p2->next == nullptr)
            {
                break;
            }
            p1->next = p2->next;
            p1 = p2->next;
            swap(p1, p2);
            ++count;
        }
        return head;
    }
};