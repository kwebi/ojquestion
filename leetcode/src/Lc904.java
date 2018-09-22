import java.util.ArrayList;
import java.util.List;

public class Lc904 {
    public int totalFruit(int[] tree) {
        int m = tree.length;
        int[] dp = new int[m];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (dp[i] > 1) {
                continue;
            }
            int tmp = 0;
            List<Integer> type = new ArrayList<>(2);
            type.add(tree[i]);
            tmp++;
            int j;
            int diff=m;
            for (j = i; j < m; j++) {
                if (!type.contains(tree[j]) && type.size() < 2) {
                    type.add(tree[j]);
                    tmp++;
                    diff = j;
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
            for (int k=i;k<diff;k++) {
                dp[k] = ans-(k-i);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        System.out.println(new Lc904().totalFruit(new int[] {0,0,0,0,0,0,0,0,0,0}));
    }
}
