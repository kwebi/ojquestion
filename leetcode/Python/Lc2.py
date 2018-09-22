class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ans = ListNode(0)
        p = ans
        sum1 = 0
        sum2 = 0
        b = 0
        p1 = l1
        while p1 != None:
            sum1 += p1.val * (10 ** b)
            b += 1
            p1 = p1.next

        b = 0

        p2 = l2
        while p2 != None:
            sum2 += p2.val * (10 ** b)
            b += 1
            p2 = p2.next

        sum = sum1 + sum2
        i = 0
        while sum/(10**i)>=1:
            i += 1

        if sum == 0:
            i += 1

        j  =0
        while j<i:
            p.next = ListNode((sum//(10**j))%10)
            p = p.next
            j += 1

        ans = ans.next
        return ans

l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)
l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

ans = Solution().addTwoNumbers(l1,l2)