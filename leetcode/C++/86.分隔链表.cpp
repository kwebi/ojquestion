/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (44.79%)
 * Total Accepted:    5.1K
 * Total Submissions: 11.4K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *h1 = nullptr, *h2 = nullptr;
        ListNode *p1 = nullptr, *p2 = nullptr;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (p->val < x)
            {
                if (p1 == nullptr)
                {
                    h1 = p;
                    p1 = p;
                }
                else
                {
                    p1->next = p;
                    p1 = p;
                }
            }
            else
            {
                if (p2 == nullptr)
                {
                    h2 = p;
                    p2 = p;
                }
                else
                {
                    p2->next = p;
                    p2 = p;
                }
            }
            p = p->next;
        }
        if (p2)
            p2->next = nullptr;
        if (p1)
            p1->next = h2;
        return h1 ? h1 : h2;
    }
};
