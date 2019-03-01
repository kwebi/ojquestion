/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (52.58%)
 * Total Accepted:    45K
 * Total Submissions: 85.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "listnode.h"
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *res = nullptr;
        if (p1 == nullptr)
            return p2;
        else if (p2 == nullptr)
            return p1;
        else if (p1->val <= p2->val)
        {
            res = p1;
            p1 = p1->next;
        }
        else
        {
            res = p2;
            p2 = p2->next;
        }

        ListNode *last = res;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                last->next = p1;
                last = p1;
                p1 = p1->next;
            }
            else
            {
                last->next = p2;
                last = p2;
                p2 = p2->next;
            }
        }
        if (p1 == nullptr)
            last->next = p2;
        else
        {
            last->next = p1;
        }
        return res;
    }
};
