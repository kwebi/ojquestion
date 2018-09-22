import java.util.ArrayList;
import java.util.List;

public class Lc904 {
    public int totalFruit(int[] tree) {
        int m = tree.length;
        int ans = 0;
        for (int i = 0; i < tree.length; i++) {
            int tmp = 0;
            List<Integer> type = new ArrayList<>(2);
            type.add(tree[i]);
            tmp++;
            if (ans >= m) {
                break;
            }
            m--;
            for (int j = i; j < tree.length; j++) {
                if (!type.contains(tree[j]) && type.size() < 2) {
                    type.add(tree[j]);
                    tmp++;
                } else if (type.contains(tree[j])) {
                    if (j == i) continue;
                    tmp++;
                } else if (!type.contains(tree[j])) {
                    break;
                }
            }
            if (ans <= tmp) {
                ans = tmp;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        System.out.println(new Lc904().totalFruit(new int[] {1,2,1}));
    }
}

