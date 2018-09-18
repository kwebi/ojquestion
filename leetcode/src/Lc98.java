public class Lc98 {
    public boolean isValidBST(TreeNode root) {
        boolean ans = true;
        boolean a1=true;
        boolean a2=true;
        if (root == null) return true;
        else {
            if (root.left != null) {
                if (root.val <= max(root.left)||root.val<=root.left.val) {
                    return false;
                }
                a1= isValidBST(root.left);
            }
            if (root.right != null) {
                if (root.val >= min(root.right) || root.val >= root.right.val) {
                    return false;
                }
                a2=isValidBST(root.right);
            }
        }
        ans = a1&&a2;
        return ans;
    }
    public int max(TreeNode root) {
        if (root.right == null) {
            return root.val;
        }
        else {
            return max(root.right);
        }
    }
    public int min(TreeNode root) {
        if (root.left == null) {
            return root.val;
        }
        else {
            return min(root.left);
        }
    }
}
