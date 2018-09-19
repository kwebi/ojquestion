public class Lc100 {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        boolean ans;
        boolean a1=true;
        boolean a2=true;
        if (p == null) {
            if (q != null) {
                return false;
            }
            return true;
        }
        else {
            if (q == null) {
                return false;
            }
            if (p.val != q.val) {
                return false;
            }
            a1=isSameTree(p.left,q.left);
            a2=isSameTree(p.right,q.right);
        }
        ans = a1 && a2;
        return ans;
    }
}
