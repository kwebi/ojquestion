
import java.util.ArrayList;
import java.util.List;

public class Lc95 {
    public List<TreeNode> generateTrees(int n) {
        return buildTree(1,n);
    }
    private List<TreeNode> buildTree(int start, int end) {
        List list = new ArrayList();
        if (start > end) {
            return list;
        }
        else if (start == end) {
            TreeNode node = new TreeNode(start);
            list.add(node);
            return list;
        }
        else {
            for (int i = start; i <= end; i++) {
                List<TreeNode> left = new ArrayList();
                List<TreeNode> right = new ArrayList();
                left = buildTree(start, i-1);
                right = buildTree(i+1, end);
                if (left.size()==0) {
                    if (right.size()==0) {
                        TreeNode root = new TreeNode(i);
                        root.left = null;
                        root.right = null;
                        list.add(root);
                    } else {
                        for (TreeNode r: right) {
                            TreeNode ptr = new TreeNode(i);
                            ptr.left = null;
                            ptr.right = r;
                            list.add(ptr);
                        }
                    }
                } else {
                    if (right.size()==0) {
                        for (TreeNode r: left) {
                            TreeNode ptr = new TreeNode(i);
                            ptr.left = r;
                            ptr.right = null;
                            list.add(ptr);
                        }
                    } else {
                        for (TreeNode l: left) {
                            for (TreeNode r: right) {
                                TreeNode ptr = new TreeNode(i);
                                ptr.left = l;
                                ptr.right = r;
                                list.add(ptr);
                            }
                        }
                    }
                }
            }
        }
        return list;
    }
}

