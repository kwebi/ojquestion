import java.util.ArrayList;
import java.util.List;

public class Lc94 {
    private static List<Integer> list;
    public List<Integer> inorderTraversal(TreeNode root) {
        list = new ArrayList<>();
        traversal(root);
        return list;
    }
    public void traversal(TreeNode node) {
        if (node == null) {
            return;
        } else {
            traversal(node.left);
            list.add(node.val);
            traversal(node.right);
        }
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}