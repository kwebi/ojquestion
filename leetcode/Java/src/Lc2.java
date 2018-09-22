/*
the problem is not solved in Java
please look the Python version
 */

public class Lc2 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode p = ans;
        long sum1=0;
        long sum2 = 0;
        int b=0;
        for (ListNode p1 = l1; p1 != null; p1=p1.next) {
            sum1 += p1.val * (long)(Math.pow(10,b));
            b++;
        }
        b = 0;
        for (ListNode p2 = l2; p2 != null; p2=p2.next) {
            sum2 += p2.val * (long)(Math.pow(10,b));
            b++;
        }
        long sum = sum1 + sum2;
        int i=0;
        while (sum/(long) Math.pow(10,i)>=1) {
            i++;
        }
        if (sum == 0) {
            i++;
        }
        for (int j=0; j<i; j++) {
            long tmp = (long)Math.pow(10,j);
            long t = (sum/tmp);
            Long l = t % (long)10;
            int res = l.intValue();
            p.next = new ListNode(res);
            p = p.next;
        }
        ans = ans.next;
        return ans;
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
