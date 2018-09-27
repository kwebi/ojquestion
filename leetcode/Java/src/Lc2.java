/*
the problem is not solved in Java
please look the Python version
 */

public class Lc2 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode p = l1, q = l2, curr = dummyHead;
        int carry = 0;
        while (p != null || q != null) {
            int x = (p != null) ? p.val : 0;
            int y = (q != null) ? q.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if (p != null) p = p.next;
            if (q != null) q = q.next;
        }
        if (carry > 0) {
            curr.next = new ListNode(carry);
        }
        return dummyHead.next;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(9);
        ListNode l2 = new ListNode(1);
        ListNode p = l2;
        for (int i=0; i<9; i++) {
            p.next = new ListNode(9);
            p = p.next;
        }
        new Lc2().addTwoNumbers(l1,l2);
    }
}


class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
